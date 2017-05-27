const Item = require('./item')

const Excalibur = {
  name: 'Excalibur',
  description: 'The legendary sword of King Arthur',
  weight: '12 lbs',
  value: '1024 gold coins'
}

const SteelArmor = {
  name: 'Steel Armor',
  description: 'Protective covering made by steel',
  weight: '15 lbs',
  value: '805 gold coins'
}

new Item(Excalibur).describe()
console.log('')
new Item(SteelArmor).describe()
