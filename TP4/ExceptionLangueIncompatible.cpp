#include "ExceptionLangueIncompatible.h"

#include "Chanson.h"

// Notez que a ne peut pas être NULL car sinon on aurait pas pu lever l'exception...
ExceptionLangueIncompatible::ExceptionLangueIncompatible(Artiste* a, const Chanson& ch)
	: ExceptionTP(	a->getnom()+
					" ne parle que "+
					Langues::init (a->getLangue())+
					", or la chanson "+
					ch.gettitre()+
					" est en "+
					Langues::init (ch.getLangue())),

					artiste(a)
{
}


ExceptionLangueIncompatible::~ExceptionLangueIncompatible(void)
{
}

Artiste* ExceptionLangueIncompatible::getArtiste() const {
	return artiste;
}
