#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>

#include <vector>

const QString DECKBUILDERWINDOWTITLE = "Gwent Calc - Editing deck: ";
const QString COMBOWINDOWTITLE = "Gwent Calc - Editing combos: ";
const QString EXTENSIONCOMBO = ".cmb";
const QString EXTENSIONVALUE = ".val";
const QString EXTENSIONDECK = ".csv";   //Note: file saving and opening is currently hardcoded with .csv in deckeditorwindow.cpp.  Keep this in mind before changing this var.
const QString EXTENSIONSET = ".gwc";
const QString SETTINGSFILENAME = "gwentcalc.set";
const QString CARDLISTFILENAME = "cards.crd";


static QString currentDeckFilename;

#endif // GLOBALS_H
