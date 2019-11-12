#include "ast/SourceFile.h"

using namespace hdc;

SourceFile::SourceFile() {

}


SourceFile::SourceFile(std::string& path) {
    this->path = path;
}


SourceFile::~SourceFile() {
    for (int i = 0; i < imports.size(); ++i) {
        delete imports[i];
    }

    for (int i = 0; i < defs.size(); ++i) {
        delete defs[i];
    }
}

void SourceFile::add_import(Import* import) {
    imports.push_back(import);
}

void SourceFile::add_class(Class* klass) {
    classes.push_back(klass);
}

void SourceFile::add_def(Def* def) {
    defs.push_back(def);
    def->set_file(this);
}


int SourceFile::n_defs() {
    return defs.size();
}


int SourceFile::n_imports() {
    return imports.size();
}

int SourceFile::n_classes() {
    return classes.size();
}

std::string SourceFile::get_path() {
    return path;
}

Class* SourceFile::get_class(int i) {
    if (i < classes.size()) {
        return classes[i];
    }

    return NULL;
}

Def* SourceFile::get_def(int i) {
    if (i < defs.size()) {
        return defs[i];
    } else {
        return NULL;
    }
}


Import* SourceFile::get_import(int i) {
    if (i < imports.size()) {
        return imports[i];
    } else {
        return NULL;
    }
}

void SourceFile::accept(Visitor* visitor) {
    visitor->visit(this);
}
