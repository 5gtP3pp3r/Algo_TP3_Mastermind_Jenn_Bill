template <class T>
Noeud<T>::Noeud()
{
}

template <class T>
Noeud<T>::~Noeud()
{
}

template <class T>
Noeud<T> * Noeud<T>::GetSuivant()
{
	return suivant;
}

template <class T>
void Noeud<T>::SetSuivant(Noeud<T> * _suivant)
{
	suivant = _suivant;
}

template <class T>
Noeud<T> * Noeud<T>::GetPrecedent()
{
	return precedent;
}

template <class T>
void Noeud<T>::SetPrecedent(Noeud<T> * _precedent)
{
	precedent = _precedent;
}

template <class T>
T * Noeud<T>::GetContent()
{
	return content;
}

template <class T>
void Noeud<T>::SetContent(T * _content)
{
	content = _content;
}


