class Item: # python3
    def __init__(self, name, description, weight, value):
        self.name = name
        self.description = description
        self.weight = weight
        self.value = value

    def describe(self):
        msg = """Name        = {}\nDescription = {}\nWeight      = {} lbs\nValue       = {} gold coins
        """.format(self.name, self.description, self.weight, self.value)
        return msg

myItem = Item("Excalibur", "The legendary sword of King Arthur", 12, 1024)
print (myItem.describe())

myItem = Item("Steel Armor", "Protective covering made by steel", 15, 805)
print (myItem.describe())