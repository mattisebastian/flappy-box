#include "flappy_box/view/box_audible.hpp"

using namespace ::flappy_box::view;

BoxAudible::BoxAudible()
{	
	
	// Eine Geräuschquelle _al_box_source definieren mittels alGenSources und alSource3f, die
	// das Spielobjekt repräsentiert mit der Position 0.5[m] auf der x-Achse (rechte Seite) hat
	ALuint _al_box_source[2];
	alGenSources( 2, _al_box_source );
	// TODO: Die zu übergebene Position ausbessern, source[0] = Position 0.5[m] und source[1] = Position -0.5[m]
	alSource3f( _al_box_source[0], AL_POSITION, (PointerAufBox::getPositionVec() + (0.5, 0, 0)) );
	alSource3f( _al_box_source[1], AL_POSITION, (PointerAufBox::getPositionVec() + (-0.5, 0, 0)) );
	

	// Einen Soundpuffer erzeugen mit 10[s]-anhaltender Sinusschwingung mit base_frequency 
	ALuint _al_box_buffer[2];
	alutCreateBufferWaveform(ALUT_WAVEFORM_SINE, base_frequency, 45, 10000);
	alutCreateBufferWaveform(ALUT_WAVEFORM_SINE, target_frequency, 45, 10000);
	// oder ?
	//_al_box_buffer[0] = alutCreateBufferWaveform(ALUT_WAVEFORM_SINE, base_frequency, 45, 10000);
	//_al_box_buffer[1] = (ALUT_WAVEFORM_SINE, target_frequency, 45, 10000);
	alGenBuffers(2, _al_box_buffer);
	

	// Soundpuffer der Geräuschquelle zuweisen und Für Geräuschquelle die Wiedergabe in
	// Endlosschleife (AL_LOOPING) aufrufen
	alSourcei(_al_box_source[0], AL_BUFFER, _al_box_buffer[0]);
	alSourcei(_al_box_source[1], AL_BUFFER, _al_box_buffer[1]);
	alSourcei(_al_box_source[0], AL_LOOPING, AL_TRUE);
	alSourcei(_al_box_source[1], AL_LOOPING, AL_TRUE);

	// Wiedergabe der Geräuschquelle starten
	alSourcePlay(_al_box_source[0]);
	alSourcePlay(_al_box_source[1]);
}  

void BoxAudible::auralize(::view::AlRenderer& al_renderer)
{
	//shared_ptr<flappy_box::model::Box> box = al_renderer.game_model();
	// Verhältnis = (Ziel-Fq + 10*Absolute(z-Postition)) / Basis-Fq
	pitch_diff = (target_frequency + 10 * BoxAbsolutWertVonZ) / base_frequency; 
	alSourcef( _al_box_source[0], AL_PITCH, pitch_diff );
}
