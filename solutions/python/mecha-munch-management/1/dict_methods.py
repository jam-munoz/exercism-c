"""Functions to manage a users shopping cart items."""


def add_item(current_cart, items_to_add):
    """Add items to shopping cart.

    Parameters:
        current_cart (dict): The current shopping cart.
        items_to_add (iterable): The items to add to the cart.

    Returns:
        dict: The updated user cart dictionary.
    """
    for item in items_to_add:
        if current_cart.setdefault(item, 0) != item:
            current_cart[item] += 1
    return current_cart

def read_notes(notes):
    """Create user cart from an iterable notes entry.

    Parameters:
        notes (iterable): Group of items to add to cart.

    Returns:
        dict: A user shopping cart dictionary.
    """
    dict = {}
    for item in notes:
        if dict.setdefault(item, 0) != item:
            dict[item] += 1
    return dict

def update_recipes(ideas: dict, recipe_updates: tuple):
    """Update the recipe ideas dictionary.

    Parameters:
        ideas (dict): The "recipe ideas" dict.
        recipe_updates (iterable): Updates for the ideas section.(str, dict)

    Returns:
        dict: The updated "recipe ideas" dict.
    """
    ideas.update(recipe_updates)
    return ideas

def sort_entries(cart):
    """Sort a user's shopping cart in alphabetical order.

    Parameters:
        cart (dict): A user's shopping cart dictionary.

    Returns:
        dict: A user's shopping cart sorted in alphabetical order.
    """
    return dict(sorted(cart.items()))

def send_to_store(cart, aisle_mapping):
    """Combine user's order to aisle and refrigeration information.

    Parameters:
        cart (dict): The user's shopping cart dictionary.
        aisle_mapping (dict): The aisle and refrigeration information dictionary.

    Returns:
        dict: The fulfillment dictionary ready to send to store.
    """
    D = dict(sorted(cart.items(), reverse=True))
    for item in aisle_mapping:
        if item in D:
            D[item] = [D[item], *aisle_mapping[item]]
    return D

def update_store_inventory(fulfillment_cart, store_inventory):
    """Update store inventory levels with user order.

    Parameters:
        fulfillment cart (dict): The fulfillment cart to send to store.
        store_inventory (dict): The stores available inventory.

    Returns:
        dict: The store_inventory updated.
    """
    for item in fulfillment_cart:
        if item in store_inventory:
            store_inventory[item][0] -= fulfillment_cart[item][0]
            if store_inventory[item][0] <= 0:
                store_inventory[item][0] = 'Out of Stock'
    return store_inventory