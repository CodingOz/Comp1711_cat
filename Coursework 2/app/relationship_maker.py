from app import app, db, admin, forms, models
from flask_admin.contrib.sqla import ModelView
from .models import Users, Items, Supplier, Sales
from datetime import datetime

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

link_item_to_supplier("Ice scream charm ","keys are us ")
link_item_to_supplier("House Keychain with Ring ","keys are us ")
link_item_to_supplier("Fur Heart Keychain ","keys are us ")
link_item_to_supplier("Fur Pom-Pom Keycharm","Bob's pins ")
link_item_to_supplier("silver motorbike key charm","Bob's pins ")
link_item_to_supplier("Leather Tassel and Bird Motif Keyring with Swivel Clasp ","Bob's pins ")
link_item_to_supplier(" Golden sequin memory stick keyring ","James and sons ")
link_item_to_supplier("Gold Elephant Keyring","James and sons ")
link_item_to_supplier("Blue Wooden Heart Keychain with Twine ","James and sons ")
