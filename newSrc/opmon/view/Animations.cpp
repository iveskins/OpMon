#include "Animations.hpp"
#include "MainFrame.hpp"
UNS

namespace OpMon{
  namespace Model{
    
    namespace Animations {

      bool init = false;
      /**
       * check if animations has been initialized.
       */
      void anim_check_init() {
	if (!init) {
	  handleError("Error : Uninitialized animations", true);
	}
      }

      GameStatus animWinOpen(sf::RenderTexture &window, sf::Sprite const &bg) {
	anim_check_init(); //Verification of animation initialization
	//Variables declaration
	sf::Sprite anim;
	int ancientChrono = 0;

	//Frame by frame
	for (int i = 0; i < 6; i++) {
	  if ((ticks.getElapsedTime().asMilliseconds() - ancientChrono) >= 33) {
            Main::mainframe.window.pollEvent(events);
            ancientChrono = ticks.getElapsedTime().asMilliseconds();
	    Controller::checkQuit();
	    if(Model::Data::endGame){
	      return GameStatus::STOP;
	    }
	    anim.setTexture(fen[i]);
            window.clear(sf::Color::White);
            window.draw(bg);
            window.draw(anim[i]);

            window.display();
            Main::mainframe.winRefresh();
	  } else {
            Utils::wait(200 - (ticks.getElapsedTime().asMilliseconds() - ancientChrono));
            i--;
	  }
	}
	return GameStatus::CONTINUE;
      }

      GameStatus animWinClose(sf::RenderTexture &window, sf::Sprite const &bg) {
	//Se rÃ©ferer aux commentaires de la fonction prÃ©cÃ©dente
	anim_check_init();
	//Variables declaration
	sf::Sprite anim;
	int ancientChrono = 0;
	for (int i = 5; i >= 0; i--) {
	  if ((ticks.getElapsedTime().asMilliseconds() - ancientChrono) >= 33) {
            ancientChrono = ticks.getElapsedTime().asMilliseconds();
	    Controller::checkQuit();
	    if(Model::Data::endGame){
	      return GameStatus::STOP;
	    }
	    anim.setTexture(fen[i]);

            window.clear(sf::Color::White);

            window.draw(bg);
            window.draw(anim[i]);

            window.display();
            Main::mainframe.winRefresh();
	  } else {
            Utils::wait(200 - (ticks.getElapsedTime().asMilliseconds() - ancientChrono));
            i++;
	  }
	}
	return GameStatus::CONTINUE;
      }


    }
  }
}
