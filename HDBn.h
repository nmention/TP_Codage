//
// Created by nmention on 31/10/22.
//

#ifndef TP_HDB_H
#define TP_HDB_H

// Encodage d'une séquence de bits suivant le mode choisie : HDB2, HDB3 ou Arithmétique
void encodage(int *bits, char *mode, int *result);
void decode(int *result, char *mode, int *bits);

#endif //TP_HDB_H
