#include "infointerface.h"

InfoInterface::InfoInterface()
{

}

void InfoInterface::readDayFile(string filename)
{
    if(purchaseList.length() == 0)
    {
        purchaseList =  FileManager::readDayFile(FILEDIR + filename + FILETYPE);
    }
    else
    {
        purchaseList += FileManager::readDayFile(FILEDIR + filename + FILETYPE);
    }
}

string InfoInterface::getFullReport(){
    std::string out;
    stringstream priceStream;
    stringstream quantityStream;
    for (int i = 0; i < purchaseList.length(); i++)
    {
          priceStream.str("");
          quantityStream.str("");
          priceStream.clear();
          quantityStream.clear();
          out += purchaseList[i].getProductName() + "\n";
          priceStream << purchaseList[i].getProductPrice();
          out += priceStream.str();
          out += "\t";
          quantityStream << purchaseList[i].getProductQuantity();
          out += quantityStream.str();
          out += "\n";
    }
    return out;
}
