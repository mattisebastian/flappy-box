# Ü4 CPP4CG

Fehler:
-------

>engine.cpp
>gamemodel() & gamelogik()
>const & nicht-const Versionen
Referenz auf Argumente muss entfernt werden, also das "&" entfernen.

## Vorbereitungen

Modularität:

View: GlRenderer, AlRenderer
Controller: Logic
--> interpretieren bzw. aktualisieren das Modell lediglich


MVC-Pattern

view: lesend auf model zugreifen
controller: lese- und schreibzugriff


controller::glutEngine verbindet Modell und Delegierte

model::Game und model::GameObject speichern Zustand des Spiels und der
darin enthaltenen Objekte.

Entscheidung: eigenen Vektorklasse oder Eigen 3

## Modell, Komponenten und deren Delegierte

model::Game stellt Schnitstelle zwischen View und Controller dar.


## 4.1 Umbau der Engine

\maketick

## 4.2 Factory Klasse zur Erzeugung von Delegierten

TODO: Delegates für alles implementieren 

## 4.3 Nutzung von Delegierten

## 4.4 Integration einer einfachen Spiellogik

Aufteilungsmöglichkeit:

TODO: Audio / Physik




## 4.2 Aufrufe:

### statische Funktion:

static shared_ptr < Out > func (const shared_ptr < In >& in ) {return make_shared < Out > ( in_oder_anders )};

register_module<T> (func)

### eine member Methode:

wie oben nur ohne static

### functor

	class meineKlasse {
	public: 
		shared_ptr < Out > operator() (const shared_ptr < In >& in ) {return make_shared < Out > ( in_oder_anders )}

	};
	












