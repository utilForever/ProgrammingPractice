const expect = require('chai').expect

const Item = require('./item')

const excalibur = new Item({
  name: 'Excalibur',
  description: 'The legendary sword of King Arthur',
  weight: '12 lbs',
  value: '1024 gold coins'
})

const steelArmor = new Item({
  name: 'Steel Armor',
  description: 'Protective covering made by steel',
  weight: '15 lbs',
  value: '805 gold coins'
})

describe('Item', function () {
  it('should have expected field', function () {
    expect(excalibur).to.have.property('name', 'Excalibur')
    expect(excalibur).to.have.property('description', 'The legendary sword of King Arthur')
    expect(excalibur).to.have.property('weight', '12 lbs')
    expect(excalibur).to.have.property('value', '1024 gold coins')

    expect(steelArmor).to.have.property('name', 'Steel Armor')
    expect(steelArmor).to.have.property('description', 'Protective covering made by steel')
    expect(steelArmor).to.have.property('weight', '15 lbs')
    expect(steelArmor).to.have.property('value', '805 gold coins')
  })

  describe('#describe()', function () {
    it('should log proper description', function () {
      excalibur.describe()
      console.log('')
      steelArmor.describe()
    })
  })
})
