class Item:
    def __init__(self, name, description, weight, value):
        self.name = name
        self.description = description
        self.weight = weight
        self.value = value

class Weapon(Item):
    def __init__(self, name, description, weight, value, damage):
        Item.__init__(self, name, description, weight, value)
        self.damage = damage

    def desribe(self):
        msg = """Name        = {}\nDescription = {}\nWeight      = {}\nValue       = {}\nDamage      = {}
        """.format(self.name, self.description, self.weight, self.value, self.damage)
        return msg

class Armor(Item):
    def __init__(self, name, description, weight, value, defense):
        Item.__init__(self, name, description, weight, value)
        self.defense = defense

    def desribe(self):
        msg = """Name        = {}\nDescription = {}\nWeight      = {}\nValue       = {}\nDefense     = {}
        """.format(self.name, self.description, self.weight, self.value, self.defense)
        return msg


myWeapon = Weapon("Excalibur", "The legendary sword of King Arthur", 12, 1024, 24)
print(myWeapon.desribe())
myArmor = Armor("Steel Armor", "Protective covering made by steel", 15, 805, 18)
print(myArmor.desribe())
