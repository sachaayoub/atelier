
exercice 1 :


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Ressource {
protected:
    int id;
    string titre;
    string auteur;
    int annee;
public:
    Ressource(int i, string t, string a, int an) : id(i), titre(t), auteur(a), annee(an) {}
    virtual void afficherInfos() const {
        cout << "ID: " << id << ", Titre: " << titre << ", Auteur: " << auteur << ", Annee: " << annee << endl;
    }
    virtual void telecharger() const {
        cout << "Telechargement de " << titre << endl;
    }
    bool operator==(const Ressource& r) const { return id == r.id; }
    string getTitre() const { return titre; }
    string getAuteur() const { return auteur; }
    int getAnnee() const { return annee; }
    virtual ~Ressource() {}
};

class Telechargeable {
public:
    virtual void telecharger() const {
        cout << "Cette ressource est telechargeable" << endl;
    }
    void afficherMessage() const {
        cout << "Disponible au telechargement" << endl;
    }
    virtual ~Telechargeable() {}
};

class Livre : public Ressource, public Telechargeable {
    int pages;
public:
    Livre(int i, string t, string a, int an, int p) : Ressource(i, t, a, an), pages(p) {}
    void afficherInfos() const override {
        Ressource::afficherInfos();
        cout << "Type: Livre, Pages: " << pages << endl;
    }
    void telecharger() const override {
        cout << "Telechargement du livre " << getTitre() << endl;
    }
};

class Magazine : public Ressource, public Telechargeable {
    int numero;
public:
    Magazine(int i, string t, string a, int an, int n) : Ressource(i, t, a, an), numero(n) {}
    void afficherInfos() const override {
        Ressource::afficherInfos();
        cout << "Type: Magazine, Numero: " << numero << endl;
    }
    void telecharger() const override {
        cout << "Telechargement du magazine " << getTitre() << endl;
    }
};

class Video : public Ressource, public Telechargeable {
    double duree;
public:
    Video(int i, string t, string a, int an, double d) : Ressource(i, t, a, an), duree(d) {}
    void afficherInfos() const override {
        Ressource::afficherInfos();
        cout << "Type: Video, Duree: " << duree << " minutes" << endl;
    }
    void telecharger() const override {
        cout << "Telechargement de la video " << getTitre() << endl;
    }
};

class Mediatheque {
    vector<Ressource*> ressources;
public:
    void ajouter(Ressource* r) { ressources.push_back(r); }
    void afficher() const {
        cout << "Contenu de la mediatheque:" << endl;
        for (auto r : ressources) r->afficherInfos();
    }
    Ressource* rechercher(string titre) const {
        for (auto r : ressources) if (r->getTitre() == titre) return r;
        return nullptr;
    }
    Ressource* rechercher(string auteur, int annee) const {
        for (auto r : ressources) if (r->getAuteur() == auteur && r->getAnnee() == annee) return r;
        return nullptr;
    }
    ~Mediatheque() {
        for (auto r : ressources) delete r;
    }
};

int main() {
    Mediatheque med;
    Livre* l = new Livre(1, "Les Miserables", "Victor Hugo", 1862, 1200);
    Magazine* m = new Magazine(2, "Science et Vie", "Redaction", 2025, 341);
    Video* v = new Video(3, "Apprendre le C++", "OpenAI", 2024, 90.5);

    med.ajouter(l);
    med.ajouter(m);
    med.ajouter(v);

    med.afficher();

    cout << "Telechargements:" << endl;
    l->telecharger();
    m->telecharger();
    v->telecharger();

    cout << "Recherche:" << endl;
    Ressource* r = med.rechercher("Les Miserables");
    if (r) {
        cout << "Ressource trouvee: ";
        r->afficherInfos();
    }
    else {
        cout << "Ressource non trouvee" << endl;
    }

    cout << "Comparaison:" << endl;
    if (*l == *v)
        cout << "Meme ID" << endl;
    else
        cout << "IDs differents" << endl;

    return 0;
}


exercice 2 :

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Client {
public:
    string nom;
    string cin;
    int id;
    Client(string n, string c, int i) : nom(n), cin(c), id(i) {}
};

class CompteBancaire {
    int code;
public:
    int numero;
    double solde;
    Client* client;
    CompteBancaire(int num, double s, int c, Client* cl) : numero(num), solde(s), code(c), client(cl) {}
    friend class AgentBancaire;
};

class AgentBancaire {
public:
    string nom;
    AgentBancaire(string n) : nom(n) {}
    void voirCode(CompteBancaire& c) { cout << c.code << endl; }
    void transfert(CompteBancaire& a, CompteBancaire& b, double m) {
        if (a.solde >= m) {
            a.solde -= m;
            b.solde += m;
        }
    }
};

class Banque {
public:
    vector<Client*> clients;
    vector<CompteBancaire*> comptes;
    void ajouterClient(Client* c) { clients.push_back(c); }
    void ajouterCompte(CompteBancaire* c) { comptes.push_back(c); }
    void afficher() {
        for (auto c : comptes) {
            cout << c->client->nom << " " << c->solde << endl;
        }
    }
};

int main() {
    Client a("Ali", "AB123", 1);
    Client b("Sara", "CD456", 2);

    CompteBancaire ca(100, 5000, 1111, &a);
    CompteBancaire cb(200, 2000, 2222, &b);

    Banque banque;
    banque.ajouterClient(&a);
    banque.ajouterClient(&b);
    banque.ajouterCompte(&ca);
    banque.ajouterCompte(&cb);

    AgentBancaire agent("Karim");
    agent.transfert(ca, cb, 1000);

    banque.afficher();
    agent.voirCode(ca);
}

