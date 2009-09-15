
unistring getModuleNameFromFileName(unistring fname){
    unistring::size_type i = fname.length()-1;
    while (i && fname[i--] != ':');
    if (!i) {
        fname = fname;
    } else {
        SYSTEMERRORn("--== zaglushka module using ==--");
        fname = "errornaME.TXT";
    }

    // oaaeyai ?anoe?aiey
    unistring newname = "";
    i=0;
    while (i<fname.length()){
        if (fname[i] == '.'){
            return newname;
        }
        newname += fname[i++];
    }

    return newname;
};

