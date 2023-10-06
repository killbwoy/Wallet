#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

#include "XmlFile.h"
#include "Markup.h"
#include "User.h"

using namespace std;

class FileWithUsers : public XmlFile {

    string fileNameWithUsers;

public:
    FileWithUsers(string fileNameWithUsers) : XmlFile(fileNameWithUsers){};
    void addUserToFile(User user);
    vector <User> loadUserFromFile();
    bool changePasswordLoggedUser(vector <User>::iterator itr);
};

#endif
