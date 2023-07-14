class Hashtable {
private:
    static const int hashsize = 250;
    list<pair<string, ptr>> magicTable[hashsize];

public:
    bool isEmpty();
    int hashFunction(string magicString);
    void insert(string key, ptr data);
    ptr searchHash(string key);
};

bool Hashtable::isEmpty() {
    int total = 0;
    for (int i = 0; i < hashsize; i++) {
        total += magicTable[i].size();
    }

    if (total == 0) {
        return true;
    } else {
        return false;
    }
}

int Hashtable::hashFunction(string magicString) {
    for (int j = 0; j < magicString.length(); j++) {
        magicString[j] = toupper(magicString[j]);
    }
    int length = magicString.length();
    int letterTotal = 0;

    for (int i = 0; i < length; i++) {
        char thisLetter = magicString[i];
        int thisValue = (int)thisLetter;
        letterTotal += thisValue;
    }

    return letterTotal;
}

void Hashtable::insert(string key, ptr data) {
    int hashcode = hashFunction(key);
    auto& block = magicTable[hashcode];
    auto beginning = begin(block);
    bool exists = false;

    for (; beginning != end(block); ++beginning) {
        if (beginning->first == key) {
            exists = true;
            beginning->second = data;
            break;
        }
    }

    if (!exists) {
        block.emplace_back(key, data);
    }
}

ptr Hashtable::searchHash(string key) {
    int hashcode = hashFunction(key);
    auto& block = magicTable[hashcode];
    auto beginning = begin(block);
    for (; beginning != end(block); ++beginning) {
        if (beginning->first == key) {
            return beginning->second;
        }
    }
    return nullptr;
}