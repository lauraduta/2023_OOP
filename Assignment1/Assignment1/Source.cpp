#include <iostream>
#include <string>
#include <sstream> // pt istringstream
using namespace std;

class Product {
private:
    int id;
    string name;
    string description;
    double price;
    string priceHistory;

public:
    Product(int _id, const string& _name, const string& _description, double _price, const string& _priceHistory) {
        id = _id;
        name = _name;
        description = _description;
        price = _price;
        priceHistory = _priceHistory;
    }

    Product(const Product& other) {
        id = other.id;
        name = other.name;
        description = other.description;
        price = other.price;
        priceHistory = other.priceHistory;
    }

    ~Product() {
    }

    double getPriceAverage() {
        double sum = price;
        istringstream iss(priceHistory);
        double historicalPrice;

        while (iss >> historicalPrice) {
            sum += historicalPrice;
        }

        return sum;
    }

    void setPrice(double newPrice) {
        istringstream iss(priceHistory);
        double historicalPrice;

        ostringstream oss;
        oss << newPrice;

        while (iss >> historicalPrice) {
            oss << " " << historicalPrice;
        }

        priceHistory = oss.str();
        price = newPrice;
    }

    void setName(const string& newName) {
        name = newName;
    }

    string getName() const {
        return name;
    }

    void setDescription(const string& newDescription) {
        description = newDescription;
    }

    string getDescription() const {
        return description;
    }

    void setPriceHistory(const string& newPriceHistory) {
        priceHistory = newPriceHistory;
    }
};

int main() {
    int id;
    string name, description;
    double price;
    string priceHistory;

    cout << "Enter ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter description: ";
    getline(cin, description);

    cout << "Enter price: ";
    cin >> price;

    cin.ignore();

    cout << "Enter price history (separated by spaces): ";
    getline(cin, priceHistory);

    Product product1(id, name, description, price, priceHistory);

    cout << "Product name: " << product1.getName() << endl;
    cout << "Product description: " << product1.getDescription() << endl;
    cout << "Product average price: " << product1.getPriceAverage() << endl;

    return 0;
}
