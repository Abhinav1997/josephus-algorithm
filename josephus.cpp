#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    unsigned int people, killfreq, survivor;
    unsigned int left = 0, num;

    std::cout << "Enter the initial number of people : ";
    std::cin >> people;
    std::cout << "Enter the person number to be killed : ";
    std::cin >> killfreq;
    std::cout << "Enter the number of survivor : ";
    std::cin >> survivor;

    if(survivor == 0) {
        std::cout << "\nEveryone is dead";
        return 0;
    } else if(survivor < 0) {
        survivor = 1;
    }

    std::vector<int> peopleList;
    peopleList.reserve(people);

    for(unsigned int i = 1; i <= people; ++i) {
        peopleList.push_back(i);
    }

    while(peopleList.size() > survivor) {
            num = killfreq - left;

            if(num > peopleList.size()) {
                while(num > peopleList.size()) {
                    num = num - peopleList.size();
                }
            }

            while(num <= peopleList.size()) {
                peopleList[num - 1] = 0;
                num = num + killfreq;
            }

            for(int j = peopleList.size() - 1; j >= 0; j--) {
                    if (peopleList[j] == 0) {
                        left = peopleList.size() - (j + 1);
                        break;
                    }
            }

            peopleList.erase(std::remove(peopleList.begin(), peopleList.end(), 0), peopleList.end());
    }

    if(survivor == 1) {
        std::cout << "\nThe survivor is number " << peopleList[0];
    } else {
        std::cout << "\nThe survivors are numbers ";
        for(unsigned int k = 0; k < peopleList.size(); ++k) {
            std::cout << peopleList[k] << " ";
        }
    }

    return 0;
}
