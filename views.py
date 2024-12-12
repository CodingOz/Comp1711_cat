from flask import render_template, flash, request, redirect, url_for, session, send_from_directory
from app import app, db, admin, forms, models
from flask_admin.contrib.sqla import ModelView
from .models import Users, Items, Supplier, Sales
from datetime import datetime
from flask_login import LoginManager, login_required, logout_user, current_user, login_user
import bcrypt # bcrypt for hashing passwords
import os


admin.add_view(ModelView(Items, db.session))
admin.add_view(ModelView(Supplier, db.session))
admin.add_view(ModelView(Sales, db.session))

#setting up login manager 
login_manager = LoginManager()
login_manager.init_app(app)
login_manager.login_view = 'login'

@app.route('/favicon.ico')
def favicon():
    return send_from_directory(os.path.join(app.root_path, 'static'),
                               'favicon.ico', mimetype='image/vnd.microsoft.icon')


# gets user info
@login_manager.user_loader
def user_loader(user_id):
    user = Users.query.get(int(user_id))
    return user


def makelink(item, user, rating):

    new_sale = Sales(
        itemId=item.id,
        UserId=user.id,
        rating=rating,
        saleDate=datetime.now().strftime("%Y-%m-%d")  # Current timestamp
    )

    # Add and commit the new sale to the database
    db.session.add(new_sale)
    db.session.commit()

def link_item_to_supplier(item_name, supplier_name):

    # Query the database for the item and supplier
    item = Items.query.filter_by(name=item_name).first()
    supplier = Supplier.query.filter_by(name=supplier_name).first()

    # Validate if both exist
    if not item:
        raise ValueError(f"Item '{item_name}' does not exist.")
    if not supplier:
        raise ValueError(f"Supplier '{supplier_name}' does not exist.")

    item.supplierId = supplier.id

    db.session.commit()

    return item


@app.route('/')
def home():
    title = 'Home'

    return render_template('Home.html', title=title)


@app.route('/all-items', methods=['GET', 'POST'])
def all():
    title = 'All items'
    form = forms.searchFilters()
    items = db.session.query(models.Items)
    images = {}
    ratings = []
    containers = []

    order_by = request.args.get('order_by', 'name_asc')
    print(f"Order by parameter: {order_by}")  # Debug the order_by parameter
    
    if order_by == 'name_asc':
        items = db.session.query(models.Items).order_by(models.Items.name.asc())
    elif order_by == 'price_asc':
        items = db.session.query(models.Items).order_by(models.Items.price.asc())
    elif order_by == 'rating_desc':
        items = db.session.query(models.Items).order_by(models.Items.rating.desc())
    else:
        items = db.session.query(models.Items)  # Default order
    
    print(f"Items query executed: {items}")  # Debug the items query
    
    if items:
        for item in items:
            photos_dir = os.path.join(app.static_folder, 'photos', item.imageFile)
            ratings.append(item.averageRating)
            containers.append("star-rating" + str(item.id))
            if os.path.exists(photos_dir):
                files = os.listdir(photos_dir)
            else:
                files = []
            first_image = files[0] if files else None
            images[item.id] = first_image 

    return render_template('ItemsList.html',  
                           title=title, 
                           form=form, 
                           items=items, 
                           images=images,
                           ratings=ratings,
                           containers=containers)



@app.route('/on-sale',  methods=['GET', 'POST'])
def sale():
    title = 'On sale'

    return render_template('ItemsList.html', title=title)


@app.route('/my-basket',  methods=['GET', 'POST'])
@login_required
def basket():
    title = 'My basket'

    return render_template('ItemsList.html', title=title)


@app.route('/logout', methods=['GET', 'POST'])
@login_required
def logout():
    logout_user()
    flash('You have been logged out', 'info')
    return redirect(url_for('home'))

@app.route('/sign-up',  methods=['GET', 'POST'])
def signup():
    form = forms.signUpForm()
    if form.validate_on_submit():
        first_name = request.form['first_name']
        last_name = request.form['last_name']
        name = first_name + ' ' + last_name
        email = request.form['email']
        password = request.form['password']

        hashed = (bcrypt.hashpw(password.encode('utf-8'), bcrypt.gensalt()).decode("utf-8"))
        
        record = models.Users(name=name,
                        email=email,
                        passwordHash=hashed
                        )        
        postcode = request.form.get('postcode')
        if postcode:
            record = models.Users(name=name,
                                  email=email,
                                  postcode=postcode,
                                  passwordHash=hashed
                                  )
        db.session.add(record)
        db.session.commit()
        flash('sigh up successful! log in to continue', 'success')
        return redirect(url_for('login'))

    return render_template('SignUp.html', title='sign up', form=form)


@app.route('/login',  methods=['GET', 'POST'])
def login():
    form = forms.loginForm()

    if form.validate_on_submit():

        email = request.form['email']
        password = request.form['password']
        remember_me = form.remember_me.data

        id = db.session.execute(
            db.select(models.Users.id)
            .filter(models.Users.email == email)
            ).scalar()
        hash = db.session.execute(
            db.select(models.Users.passwordHash)
            .filter(models.Users.email == email)
            ).scalar()
        # checks the username 
        if not id:
            flash('Username or password incorrect', 'bad-input')
        
        #checks if the password hashes match
        elif not bcrypt.checkpw(password.encode('utf-8'), hash.encode('utf-8')):
            flash('Username or password incorrect', 'bad-input')
        
        #logs user in
        else:
            flash('successfully logged in')
            user = user_loader(id)
            login_user(user, remember=remember_me)

            return redirect(url_for('home'))

    return render_template('Login.html', title='login', form=form)


@app.route('/item/<int:id>', methods=['GET', 'POST'])
def show_item(id):
    item = db.session.get(models.Items, id)
    if not item:
        flash("Item not found.")
        return redirect(url_for('home'))
    
    title = item.name

    if not item:
        flash("Item not found.")
        return redirect(url_for('home'))

    image_file = os.path.join(app.static_folder, 'photos', item.imageFile)
    images =os.listdir(image_file)

    return render_template('ItemDisplay.html', title=title, item=item, images=images, ratings=[item.averageRating], containers=["star-rating"])
