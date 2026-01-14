#include <iostream>
#include <string>

using namespace std;

enum class Category {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW,
    NONE
};

struct Player {
    int id;
    string login;
    string password;

    void displayInfo() {
        cout << "ID: " << id << endl;
        cout << "Login: " << login << endl;
        cout << "Password: " << password << endl;
    }
};

class Item {
private:
    string title;
    float power;
    float mass;
    Category category;
public:
    Item(string t, float p, float m, Category c) {
        title = t;
        power = p;
        mass = m;
        category = c;
    }
    
    Item() : Item("Default", 10, 2, Category::ONEHANDED) {}
    
    Category getCategory() const { return category; }
    string getTitle() const { return title; }
    float getPower() const { return power; }
    float getMass() const { return mass; }
    
    virtual void use() = 0;
    virtual ~Item() {}
};
class SpecialItem : public Item {
private:
    float extraPower;
    
public:

    SpecialItem(string t, float p, float m, Category c, float extra)
        : Item(t, p, m, c), extraPower(extra) {}
    
    SpecialItem() : SpecialItem("Magical Sword", 20, 3, Category::ONEHANDED, 10) {}

    float getExtraPower() const { return extraPower; }

    float getPower() const override {
        return Item::getPower() + extraPower;
    }
    
    void use() override {
        cout << "Using magical item!" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    SpecialItem sword("Fire Sword", 25, 4, Category::ONEHANDED, 15);

    cout << "Item type: ";
    Category type = sword.getCategory();
    
    if (type == Category::ONEHANDED) {
        cout << "One-handed weapon" << endl;
    } else if (type == Category::TWOHANDED) {
        cout << "Two-handed weapon" << endl;
    } else if (type == Category::BOW) {
        cout << "Bow" << endl;
    } else if (type == Category::CROSSBOW) {
        cout << "Crossbow" << endl;
    } else {
        cout << "Unknown type" << endl;
    }
    
    cout << "\n=== Testing Player structure ===" << endl;
    Player player1;
    player1.id = 1001;
    player1.login = "warrior123";
    player1.password = "securePass";
    player1.displayInfo();
    
    cout << "\n=== Testing SpecialItem class ===" << endl;

    SpecialItem custom("Ice Staff", 18, 5, Category::TWOHANDED, 12);
    SpecialItem defaultItem;
    
    cout << "Custom item: " << custom.getTitle() << endl;
    cout << "Base power: " << custom.Item::getPower() << endl;
    cout << "Extra power: " << custom.getExtraPower() << endl;
    cout << "Total power: " << custom.getPower() << endl;
    cout << "Mass: " << custom.getMass() << endl;
    
    cout << "\nDefault item: " << defaultItem.getTitle() << endl;
    cout << "Total power: " << defaultItem.getPower() << endl;

    custom.use();
    
    return 0;
}
