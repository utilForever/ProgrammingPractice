class Item: # python3
	def __init__(self, name, description, weight, value):
		self.name = name
		self.description = description
		self.weight = weight
		self.value = value

	def Desribe(self):
		msg = "Name		= " + self.name + "\n"
		msg += "Description = " + self.description + "\n"
		msg += "Weight      = " + self.weight + "\n"
		msg += "Value       = " + self.value + "\n" 
		return msg

myItem = Item("Excalibur", "The legendary sword of King Arthur", "12 lbs", "1024 gold coins")
print (myItem.Desribe())

myItem = Item("Steel Armor", "Protective covering made by steel", "15 lbs", "805 gold coins")
print (myItem.Desribe())