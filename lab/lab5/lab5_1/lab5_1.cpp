#include <iostream>

using namespace std;

enum class Category {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW,
    NONE
};

enum class Identifier {
    A,
    B
};

class Item {
private:
    Category category;
    Identifier identifier;
    string title;
    float power, mass;
    
public:
    Item(string t = "NONE", float p = 0, float m = 0, 
         Category c = Category::NONE, Identifier i = Identifier::A) {
        this->title = t;
        this->power = p;
        this->mass = m;
        this->category = c;
        this->identifier = i;
        cout << "\nITEM CREATED;\n";
    }

    ~Item();
    
    string getTitle() const;
    float getMass() const;
    virtual float getPower() const;
    
    bool operator>(const Item& other) const {
        return this->getPower() > other.getPower();
    }
    
    bool operator<(const Item& other) const {
        return this->getPower() < other.getPower();
    }
    
    Category getCategory() const;
    Identifier getIdentifier() const;
    virtual void use() = 0;
};

class SpecialItem : public Item {
private:
    float extraPower;
    
public:
    SpecialItem(string t, float p, float m, Category c, 
                Identifier i, float ep)
        : Item(t, p, m, c, i), extraPower(ep) {};
    
    SpecialItem() : SpecialItem("Greatbow", 25.7, 237, 
                                Category::BOW, Identifier::B, 25) {};
    
    float getExtraPower() const;
    float getPower() const override;
    void use() override;
};

Item::~Item() {
    cout << "\nITEM DESTROYED;\n";
}

class SingleUseItem : public Item {
private:
    bool used;
    
public:
    SingleUseItem(string t = "NONE", float p = 0, float m = 0, 
               Category c = Category::NONE, Identifier i = Identifier::A, 
               bool u = 0) 
        : Item(t, p, m, c, i), used(u) {};
    
    bool isUsed() const;
    void use() override;
};

string Item::getTitle() const {
    return title;
}

float Item::getPower() const {
    return power;
}

float Item::getMass() const {
    return mass;
}

Category Item::getCategory() const {
    return category;
}

Identifier Item::getIdentifier() const {
    return identifier;
}

float SpecialItem::getExtraPower() const {
    return extraPower;
}

float SpecialItem::getPower() const {
    return Item::getPower() + extraPower;
}

bool SingleUseItem::isUsed() const {
    return used;
}

void SpecialItem::use() {
    cout << "\nSpecial attack\n";
}

void SingleUseItem::use() {
    if (isUsed() == false) {
        cout << "Single use attack" << endl;
        this->used = true;
    }
    else {
        cout << "Already used" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    SpecialItem item1("Special Sword", 30, 5, Category::ONEHANDED, 
                   Identifier::A, 15);
    
    cout << "Item: " << item1.getTitle() << endl;
    cout << "Base power: " << item1.Item::getPower() << endl;
    cout << "Extra power: " << item1.getExtraPower() << endl;
    cout << "Total power: " << item1.getPower() << endl;
    
    class TestItem : public Item {
    public:
        TestItem(string n, float p) : Item(n, p, 1, Category::ONEHANDED) {}
        void use() override {}
    };
    
    TestItem item2("Sword", 35);
    SpecialItem item3("Special Axe", 25, 6, Category::TWOHANDED, 
                         Identifier::B, 20);
    
    cout << "Sword power: " << item2.getPower() << endl;
    cout << "Special Axe total power: " << item3.getPower() << endl;
    
    if (item3 > item2) {
        cout << item3.getTitle() << " > " << item2.getTitle() 
             << " (" << item3.getPower() << " > " << item2.getPower() << ")" << endl;
    } else {
        cout << item3.getTitle() << " <= " << item2.getTitle() 
             << " (" << item3.getPower() << " <= " << item2.getPower() << ")" << endl;
    }
    
    if (item2 < item3) {
        cout << item2.getTitle() << " < " << item3.getTitle() 
             << " (" << item2.getPower() << " < " << item3.getPower() << ")" << endl;
    }
    
    SpecialItem item4("Staff", 20, 3, Category::TWOHANDED, Identifier::A, 10);
    TestItem item5("Bow", 28);
    
    cout << "\nStaff total power: " << item4.getPower() << endl;
    cout << "Bow power: " << item5.getPower() << endl;
    
    if (item4 > item5) {
        cout << "Staff stronger than Bow" << endl;
    }
    
    if (item5 < item4) {
        cout << "Bow weaker than Staff" << endl;
    }
    
    return 0;
}
