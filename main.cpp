#include "deckeditorwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //Initialization functions occur here on program startup.
    //Main window.
    QApplication a(argc, argv);
    DeckEditorWindow deckEditor;


    deckEditor.show();

    return a.exec();
}
