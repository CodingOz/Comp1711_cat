from app import db
from flask_login import UserMixin


class Users(db.Model, UserMixin):
    __tablename__ = 'Users'
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(500), nullable=False)
    email = db.Column(db.String(500), unique=True, nullable=False)
    is_active = db.Column(db.Boolean, default=True)
    postcode = db.Column(db.String(500))
    passwordHash = db.Column(db.String(500), nullable=False)

    # relationships
    sales = db.relationship("Sales", backref="user", lazy=True)  # Reference Sales table
    items = db.relationship("Items", secondary="Sales", back_populates="users", lazy=True)  # Many-to-many


class Items(db.Model):
    __tablename__ = 'Items'
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(500), nullable=False)
    description = db.Column(db.String(5000))
    imageFile = db.Column(db.String, nullable=False)
    colour = db.Column(db.String(500))
    price = db.Column(db.Float, nullable=False)
    onSale = db.Column(db.Boolean)
    salePrice = db.Column(db.Float)
    stock = db.Column(db.Integer)
    dateAdded = db.Column(db.String(500))
    averageRating = db.Column(db.Float)
    supplierId = db.Column(db.Integer, db.ForeignKey('Supplier.id'))

    # Relationship to Supplier
    supplier = db.relationship("Supplier", backref="items")

    # Relationship to Users through the Sales table
    users = db.relationship("Users", secondary="Sales", back_populates="items")


class Supplier(db.Model):
    __tablename__ = 'Supplier'
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(500), nullable=False)
    address = db.Column(db.String(5000))
    postcode = db.Column(db.String(5000))
    averageRating = db.Column(db.Float)


class Sales(db.Model):
    __tablename__ = 'Sales'
    id = db.Column(db.Integer, primary_key=True)
    rating = db.Column(db.Float)
    saleDate = db.Column(db.String(500), nullable=False)
    itemId = db.Column(db.Integer, db.ForeignKey('Items.id'), nullable=False)
    UserId = db.Column(db.Integer, db.ForeignKey('Users.id'), nullable=False)

