#ifndef TIPOSCOMUNES_H
#define TIPOSCOMUNES_H

enum class TipoApartamento{
    Basico,
    Lujo,
    Normal
};

inline char tipoApartamentoToChar(TipoApartamento tipo) {
    switch (tipo) {
    case TipoApartamento::Basico:
        return'B';
    case TipoApartamento::Lujo:
        return 'L';
    case TipoApartamento::Normal:
        return 'N';
    default:;
        //TODO
    }
}

inline TipoApartamento charToTipoApartamento(char letra) {
    switch(letra){
    case 'B': case 'b':
        return TipoApartamento::Basico;
    case 'N': case 'n':
        return TipoApartamento::Normal;
    case 'L': case 'l':
        return TipoApartamento::Lujo;
    default:; //TODO
    }
}


#endif // TIPOSCOMUNES_H
