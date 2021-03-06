#include "Dialog.hpp"


Dialog::Dialog(const sf::String *text, unsigned int sizeOfText)
  : text(text), sizeOfTxt(sizeOfText) {}

void Dialog::pass() {
    if (changeDialog == false) {
      txtEnCours[0] = text[dialog];
      txtEnCours[1] = text[dialog + 1];
      txtEnCours[2] = text[dialog + 2];
      
      // TODO: the print and the wait should be separated from the dialog update.
      Main::mainframe.printText(Main::mainframe.frame, txtEnCours);
      changeDialog = true;
      Utils::wait(50);
    } else if (dialog + 3 < sizeOfTxt) {
      Main::mainframe.dialogPass.play();
      line = 0;
      dialog+=3;
      i = 0;
      txtEnCours[0] = sf::String(" ");
      txtEnCours[1] = sf::String(" ");
      txtEnCours[2] = sf::String(" ");
      changeDialog = false;
    } else {
      is_dialog_over = true;
    }
}


void Dialog::updateTextAnimation() {
    if(!changeDialog) {
        if (i < text[line + dialog].toUtf32().size()) {
	  
            if (txtEnCours[line] == sf::String(" ")) {
                txtEnCours[line] = text[line + dialog].toUtf32()[i];
            } else if(text[line + dialog].toUtf32()[i] > 10){ 
                txtEnCours[line] += text[line + dialog].toUtf32()[i];
            }
	    UNS
	      /*cout << (char) text[line + dialog].toUtf32()[i] << "|" << text[line + dialog].toUtf32()[i] << endl;
	    cout << "Caractère : " << i << " - Ligne : " << line << endl;
	    cout << "Taille : " << text[line + dialog].toUtf32().size() << endl;*/
            i++;
        } else {
            if (line == 2) {
                changeDialog = true;
            } else {
                line++;
                i = 0;
            }
        }
    }
}


void Dialog::draw() {
  printText(View::frame, txtEnCours);
  sf::Vector2f posArrow = View::frame.mapPixelToCoords(sf::Vector2i(512-75, 512-30)); 
  arrDial.move(0, 1);
  if (arrDial.getPosition().y - posArrow.y > 5) {	
    arrDial.move(0, -6);				
  }									
  View::frame.draw(arrDial);
    
}


bool Dialog::isDialogOver() {
    return is_dialog_over;
}

void Dialog::printText(sf::RenderTexture &framee, sf::String text[]) {
    int minusPos = 32;
    dialog.setPosition(framee.mapPixelToCoords(sf::Vector2i(0, 362)));
    framee.draw(dialog);
    for(unsigned int itor = 0; itor < 3; itor++) {
      dialogText[itor].setString(text[itor].toUtf32());
      dialogText[itor].setFont(font);
      dialogText[itor].setCharacterSize(FONT_SIZE_DEFAULT);
      dialogText[itor].setColor(sf::Color::Black);
      dialogText[itor].setPosition(framee.mapPixelToCoords(sf::Vector2i(25, framee.mapCoordsToPixel(dialog.getPosition()).y + minusPos)));
      minusPos+=32;
      
      framee.draw(dialogText[itor]);
    }
}
