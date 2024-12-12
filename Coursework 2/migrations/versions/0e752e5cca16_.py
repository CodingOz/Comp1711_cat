"""empty message

Revision ID: 0e752e5cca16
Revises: 
Create Date: 2024-12-10 20:52:14.040615

"""
from alembic import op
import sqlalchemy as sa


# revision identifiers, used by Alembic.
revision = '0e752e5cca16'
down_revision = None
branch_labels = None
depends_on = None


def upgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    op.create_table('Supplier',
    sa.Column('id', sa.Integer(), nullable=False),
    sa.Column('name', sa.String(length=500), nullable=False),
    sa.Column('address', sa.String(length=5000), nullable=True),
    sa.Column('postcode', sa.String(length=5000), nullable=True),
    sa.Column('averageRating', sa.Integer(), nullable=True),
    sa.PrimaryKeyConstraint('id')
    )
    op.create_table('Users',
    sa.Column('id', sa.Integer(), nullable=False),
    sa.Column('name', sa.String(length=500), nullable=False),
    sa.Column('email', sa.String(length=500), nullable=False),
    sa.Column('is_active', sa.String(length=500), nullable=True),
    sa.Column('postcode', sa.String(length=500), nullable=True),
    sa.Column('passwordHash', sa.String(length=500), nullable=False),
    sa.PrimaryKeyConstraint('id'),
    sa.UniqueConstraint('email')
    )
    op.create_table('Items',
    sa.Column('id', sa.Integer(), nullable=False),
    sa.Column('name', sa.String(length=500), nullable=False),
    sa.Column('description', sa.String(length=5000), nullable=True),
    sa.Column('imageFile', sa.String(), nullable=False),
    sa.Column('colour', sa.String(length=500), nullable=True),
    sa.Column('price', sa.Float(), nullable=False),
    sa.Column('onSale', sa.Boolean(), nullable=True),
    sa.Column('salePrice', sa.Float(), nullable=True),
    sa.Column('stock', sa.Integer(), nullable=True),
    sa.Column('dateAdded', sa.String(length=500), nullable=True),
    sa.Column('averageRating', sa.Integer(), nullable=True),
    sa.Column('supplierId', sa.Integer(), nullable=True),
    sa.ForeignKeyConstraint(['supplierId'], ['Supplier.id'], ),
    sa.PrimaryKeyConstraint('id')
    )
    op.create_table('Sales',
    sa.Column('id', sa.Integer(), nullable=False),
    sa.Column('rating', sa.Integer(), nullable=True),
    sa.Column('saleDate', sa.String(length=500), nullable=False),
    sa.Column('itemId', sa.Integer(), nullable=False),
    sa.Column('UserId', sa.Integer(), nullable=False),
    sa.ForeignKeyConstraint(['UserId'], ['Users.id'], ),
    sa.ForeignKeyConstraint(['itemId'], ['Items.id'], ),
    sa.PrimaryKeyConstraint('id')
    )
    # ### end Alembic commands ###


def downgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    op.drop_table('Sales')
    op.drop_table('Items')
    op.drop_table('Users')
    op.drop_table('Supplier')
    # ### end Alembic commands ###
