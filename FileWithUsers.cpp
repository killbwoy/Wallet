#include "FileWithUsers.h"
#include "Markup.h"
#include "SupportMethods.h"

void FileWithUsers :: addUserToFile(User user)
{
    CMarkup xml;
    string fileNameWithUsers = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithUsers);
     if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserID", user.getUserId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getUserName());
    xml.AddElem("Surname", user.getUserSurname());

    xml.Save(fileNameWithUsers);

}

vector <User> FileWithUsers :: loadUserFromFile()
{
    User user;
    vector <User> users;

    CMarkup xml;
    string fileNameWithUsers = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithUsers);

    if (fileExists == true)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("User") == true) {

            xml.IntoElem();
            xml.FindElem( "UserID");
            int userId = atoi(xml.GetData().c_str());
            user.setupUserId(userId);
            xml.FindElem( "Login");
            string login = xml.GetData();
            user.setupLogin(login);
            xml.FindElem( "Password");
            string password = xml.GetData();
            user.setupPassword(password);
            xml.FindElem( "Name");
            string userName = xml.GetData();
            user.setupUserName(userName);
            xml.FindElem( "Surname");
            string userSurname = xml.GetData();
            user.setupUserSurname(userSurname);
            users.push_back(user);

            xml.OutOfElem();
        }
    }

    return users;
}

/*bool FileWithUsers :: checkLogin(string login) {
    CMarkup xml;
    bool fileExists = xml.Load(fileNameWithUsers);
    xml.Load(fileNameWithUsers);
    //xml.SetDoc( fileNameWithUsers );

    xml.ResetPos();
    //xml.FindElem();
    //xml.IntoElem();
    while ( xml.FindElem("LOGIN") == true ) {
        if ( xml.GetData() == login ) {
            return true;
        }
    }
    return false;
}*/
bool FileWithUsers::changePasswordLoggedUser(vector <User>::iterator itr) {
    CMarkup xml;
    string fileNameWithUsers = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithUsers);
    if (fileExists == true) {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User"))  {
            xml.IntoElem();
            xml.FindElem("UserID");
            int userId = SupportMethods::convertStringToInt(xml.GetData());
            if (userId == itr -> getUserId()) {
                xml.FindElem("Password");
                xml.SetData(itr -> getPassword());
                xml.Save(fileNameWithUsers);
                return true;
            }
            xml.OutOfElem();
        }
    }
    else {
        cout << "Can not open file with name :" << getFileName() << endl;
        return false;
    }
}
