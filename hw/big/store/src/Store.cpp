#include <store/Store.hpp>

// PRIVATE

void Store::isValid(string name) {
    if (name.empty())
        throw invalid_argument("Name cannot be empty");
}

void Store::resize() {
    Product *tmp = new Product[this->products.capacity * 2];

    for (size_t i = 0; i < this->products.capacity; i++)
        tmp[i] = this->products.products[i];
    
    delete[] this->products.products;
    this->products.capacity *= 2;
    this->products.products = tmp;
}

bool Store::repetative(string name) {
    for (size_t i = 0; i < products.quantity; i++)
        if (products.products[i].getName() == name)
            return true;
    
    return false;
}

// PUBLIC

Store::Store(string name, string address, double rent, string typeOfProperty) : Property(address, rent, typeOfProperty) {
    this->name = name;
    this->products.quantity = 0;
    this->products.capacity = D_CAP;
    this->products.products = new Product[this->products.capacity];
}

Store::Store(const Store& other) : Property(other) {
    this->name = other.name;
    this->products.capacity = other.products.capacity;
    this->products.products = new Product[this->products.capacity];
    for (size_t i = 0; i < this->products.capacity; i++) {
        this->products.products[i] = other.products.products[i];
    }
}

Store &Store::operator=(const Store& other) {
    if(this != &other) {
        Property::operator=(other);
        this->name = other.name;
        this->products.capacity = other.products.capacity;
        this->products.products = new Product[this->products.capacity];
        for (size_t i = 0; i < this->products.capacity; i++) {
            this->products.products[i] = other.products.products[i];
        }
    }
    return *this;
}

Store::~Store() {
    delete[] this->products.products;
}

// Getters

string Store::getName()const {
    return this->name;
}

products_t *Store::revision_old() const {
    products_t *v = new products_t;
    v->capacity = D_CAP;
    v->quantity = 0;
    v->products = new Product[v->capacity];
    
    for (size_t i = 0; i < this->products.quantity; i++) {
        if(this->products.products[i].getQ() < 5) {
            if(v->quantity >= v->capacity){
                    Product *tmp = new Product[v->capacity * 2];

                    for (size_t i = 0; i < v->capacity; i++)
                        tmp[i] = v->products[i];
                    
                    delete[] v->products;
                    v->capacity *= 2;
                    v->products = tmp;
            }
            v->products[v->quantity++] = this->products.products[i];
        }
    }
    
    return v;
}

vector<Product> Store::revision() const { 
    vector<Product> v;

    for(int i = 0; i < this->products.quantity; ++i)
        if(this->products.products[i].getQ() < 5) 
            v.push_back(this->products.products[i]);

    return v;
}

uint Store::getProductQuantity(string name) const {
    for (size_t i = 0; i < this->products.quantity; ++i) {
        if (this->products.products[i].getName() == name) {
            return this->products.products[i].getQ();
        }
    }
    throw invalid_argument("Product does not exist!");
}

uint Store::getProductQuantity(Product product) const {
    for (size_t i = 0; i < this->products.quantity; ++i) {
        if (this->products.products[i] == product) {
            return this->products.products[i].getQ();
        }
    }
    throw invalid_argument("Product does not exist!");
}

double Store::getProductPrice(string name) const {
    for (size_t i = 0; i < this->products.quantity; ++i) {
        if (this->products.products[i].getName() == name) {
            return this->products.products[i].getPrice();
        }
    }
    throw invalid_argument("Product does not exist!");
}

double Store::getProductPrice(Product product) const {
    for (size_t i = 0; i < this->products.quantity; ++i) {
        if (this->products.products[i] == product) {
            return this->products.products[i].getPrice();
        }
    }
    throw invalid_argument("Product does not exist!");
}

void Store::printStore()const {
    cout << "Store name: " << this->name << endl;
    cout << "Address: " << this->getAddress() << endl;
    cout << "Rent: " << this->calcRent() << endl;
    cout << "Type of property: " << this->getType() << endl;
    
    if(this->products.quantity > 0) {
        cout << "Products: " << endl;
        for (size_t i = 0; i < this->products.quantity; i++) {
            cout << "===" << this->products.products[i].getName() << "===" << endl;
            cout << "Quantity: " << this->products.products[i].getQ() << endl;
            cout << "Price: " << this->products.products[i].getPrice() << endl;
        }
    }
} 

// Setters

void Store::addProduct(string name, int quantity, double price) {
    if (this->repetative(name)) {
        throw invalid_argument("Product already exists");
    }
    if (this->products.quantity >= this->products.capacity) {
        this->resize();
    }
    this->products.products[this->products.quantity++] = Product(name, quantity, price);
}

void Store::addProduct(Product product) {
    if (this->repetative(product.getName())) {
        throw invalid_argument("Product already exists");
    }
    if (this->products.quantity >= this->products.capacity) {
        this->resize();
    }
    this->products.products[this->products.quantity++] = product;
}

void Store::restockProduct(string name, int quantity) {
    for (size_t i = 0; i < this->products.quantity; ++i) {
        if (this->products.products[i].getName() == name) {
            this->products.products[i].setQ(this->products.products[i].getQ() + quantity);
            return;
        }
    }
                throw invalid_argument("Product does not exist!");

}

void Store::restockProduct(Product product, int quantity) {
    for (size_t i = 0; i < this->products.quantity; ++i) {
        if (this->products.products[i].getName() == product.getName()) {
            this->products.products[i].setQ(this->products.products[i].getQ() + quantity);
            return;
        }
    }
                throw invalid_argument("Product does not exist!");

}

void Store::buyProduct(string name, int quantityToBuy) {
    for (size_t i = 0; i < this->products.quantity; ++i) {
        if (this->products.products[i].getName() == name) {
            if (this->products.products[i].getQ() >= quantityToBuy) {
                (this->products.products[i].getQ() > quantityToBuy) ? this->products.products[i].setQ(this->products.products[i].getQ() - quantityToBuy) : this->products.products[i].setQ(0);
                return;
            }
        }
    }
                throw invalid_argument("Product does not exist!");

}

void Store::changeProductPrice(string name, double price) {
    if (price < 0) {
        throw invalid_argument("Price can't be negative");
    }
    for (size_t i = 0; i < this->products.quantity; ++i) {
        if (this->products.products[i].getName() == name) {
            this->products.products[i].setPrice(price);
            return;
        }
    }
                throw invalid_argument("Product does not exist!");

}

void Store::changeProductPrice(Product product, double price) {
    if (price < 0) {
        throw invalid_argument("Price can't be negative");
    }
    for (size_t i = 0; i < this->products.quantity; ++i) {
        if (this->products.products[i] == product) {
            this->products.products[i].setPrice(price);
            return;
        }
    }
                throw invalid_argument("Product does not exist!");

}