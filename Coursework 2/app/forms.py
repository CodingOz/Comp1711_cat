from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField, BooleanField, SelectField, SubmitField
from wtforms.validators import Regexp, ValidationError, Length, InputRequired, Email, EqualTo, Optional
from app import db, models;
from sqlalchemy import func

# Checks that the password contains diffent types of charecters
def password_complexity_check(form, field):
       password = field.data
       # Check for uppercase letters
       if not any(char.isupper() for char in password):
              raise ValidationError('Password must contain at least one uppercase letter.')
       
       # Check for lowercase letters
       if not any(char.islower() for char in password):
              raise ValidationError('Password must contain at least one lowercase letter.')
       
       # Check for numbers
       if not any(char.isdigit() for char in password):
              raise ValidationError('Password must contain at least one number.')
       
       # Check for special characters
       if not any(char in "@$!%*?&" for char in password):
              raise ValidationError('Password must contain at least one special character.')
       
#checks that the email is unique    
def email_new_check(form, field):
       email = field.data
       count = db.session.execute(
          db.select(func.count())
          .select_from(models.Users)
          .filter(models.Users.email == email)).scalar()
       if count:
              raise ValidationError('Email is already in use') 

#
def getColors():
       options =  db.session.execute(
              db.select(func.distinct(models.Items.colour))
              ).fetchall()
       options = [option[0] for option in options]
       options.append('N/A')

       return options


def getSupplier():
       options = db.session.execute(
              db.select(func.distinct(models.Supplier.name))
              ).fetchall()
       options = [option[0] for option in options]
       options.append('N/A')
       return options

       


class signUpForm(FlaskForm):
       first_name = StringField('First Name', validators=[
              InputRequired(),
              Regexp(r'^[A-Za-z]+$',
               message="First name can only contain letters")
       ])

       last_name = StringField('Last Name', validators=[
              InputRequired(),
              Regexp(r'^[A-Za-z]+$',
               message="Last name can only contain letters")
       ])

       email = StringField('Email', validators=[
              InputRequired(), 
              Email(),
              email_new_check
       ])
 
       postcode = StringField('Postcode',validators=[
              Optional(),
              Regexp(r'^[A-Za-z0-9]+$',message='Postcode can only have letters and numbers')
       ])

       password = PasswordField('Password', validators=[
              InputRequired(),
              Length(min=10, message='Password must be at least 10 characters long'),
              password_complexity_check
       ])
              
       confirm_password = PasswordField('Confirm Password', validators=[
              InputRequired(),
              EqualTo('password', message='Passwords must match')
       ])

       submit = SubmitField('Register')


class loginForm(FlaskForm):
       email = StringField('Email', validators=[
              InputRequired(), 
              Email()
       ])
       password = PasswordField('Password', validators=[
              InputRequired()
       ])

       remember_me = BooleanField('Remember me?')
       
       submit = SubmitField('Login')



class searchFilters(FlaskForm):
       order_by = SelectField('Order by', choices=[
              'A-Z', 
              'Top Ranked', 
              'Lowest to highest price'], default='A-Z')
       



