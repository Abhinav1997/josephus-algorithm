#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> eliminate(std::vector<int> nPeople, int kill, int nSurvivor) {
    unsigned int left = 0, num;
    while(nPeople.size() > nSurvivor) {
        num = kill - left;

        if(num > nPeople.size()) {
            while(num > nPeople.size()) {
                num = num - nPeople.size();
            }
        }

        while(num <= nPeople.size()) {
            nPeople[num - 1] = 0;
            num = num + kill;
        }

        for(int j = nPeople.size() - 1; j >= 0; j--) {
            if (nPeople[j] == 0) {
                left = nPeople.size() - (j + 1);
                break;
            }
        }

        nPeople.erase(std::remove(nPeople.begin(), nPeople.end(), 0), nPeople.end());
    }

    return nPeople;
}

int main() {
    unsigned int people, killfreq, survivor;

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

    std::vector<int> peopleList, survivorList;
    peopleList.reserve(people);

    for(unsigned int i = 1; i <= people; ++i) {
        peopleList.push_back(i);
    }

    survivorList = eliminate(peopleList, killfreq, survivor);

    if(survivor == 1) {
        std::cout << "\nThe survivor is number " << survivorList[0];
    } else {
        std::cout << "\nThe survivors are numbers ";
        for(unsigned int k = 0; k < survivorList.size(); ++k) {
            std::cout << survivorList[k] << " ";
        }
    }

    return 0;
}
