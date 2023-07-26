#include "organisationuser.h"

OrganisationUser::OrganisationUser()
{
    QDir().mkdir("Organisation");
}

void OrganisationUser::SetPhoneNumberOrganisationUser(QString number)
{
    PhoneNaumber = number;
}

void OrganisationUser::SetFollowingsOrganisationUser()
{
    Followings = 0;
}

void OrganisationUser::SetFollowersOrganisationUser()
{
    Followers = 0;
}

void OrganisationUser::SetProfileImageOrganisationUser(QImage img)
{
    ProfileImage = img;
}
