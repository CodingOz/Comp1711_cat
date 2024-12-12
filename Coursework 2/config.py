import os
from datetime import timedelta

basedir = os.path.abspath(os.path.dirname(__file__))
SQLALCHEMY_DATABASE_URI = 'sqlite:///' + os.path.join(basedir, 'app.db')
SQLALCHEMY_TRACK_MODIFICATIONS = True

PERMANENT_SESSION_LIFETIME = timedelta(days=30)

WTF_CSRF_ENABLED = True
SECRET_KEY = 'a-very-secret-secret'
