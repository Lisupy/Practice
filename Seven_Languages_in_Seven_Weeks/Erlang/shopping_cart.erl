-module(shopping_cart).
-export([calc/1]).

calc(ShopingCart) -> [{Item, Quantity * Price} || {Item, Quantity, Price} <- ShopingCart].
