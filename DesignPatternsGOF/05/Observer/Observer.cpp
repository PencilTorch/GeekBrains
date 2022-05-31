#include "Observer.h"

int main() {
    Herald herald;
    herald.setAnnouncement("Glory to the emperor!");
    herald.setVoicePower(100);
    herald.changeAnnouncment();
    herald.setAnnouncement("Tomorrow is a public holiday.");
    herald.setVoicePower(50);
    herald.changeAnnouncment();

    return 0;
}