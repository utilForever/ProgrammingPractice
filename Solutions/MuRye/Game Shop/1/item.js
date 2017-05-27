class Item {
  constructor ({name, description, weight, value}) {
    this.name = name
    this.description = description
    this.weight = weight
    this.value = value
  }

  describe () {
    console.log(`Name        = ${this.name}`)
    console.log(`Description = ${this.description}`)
    console.log(`Weight      = ${this.weight}`)
    console.log(`Value       = ${this.value}`)
  }
}

module.exports = Item
