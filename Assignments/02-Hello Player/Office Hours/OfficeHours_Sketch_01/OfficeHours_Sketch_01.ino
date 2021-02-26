// game state of 0 is idle, game state of 1 is active
enum state {
  IDLE,				// 0
  ACTIVE,			// 1
  GAMEOVER			// 2
};

byte gameState = IDLE;	

byte health = 100;

void setup() {
}

void loop() {
  
  // Handle inputs from player
  if(buttonPressed()) {
    gameState = ACTIVE;
  }
  
  
  // handle inputs from neighboring blinks
	// listen to neighbors
  	//FOREACH_FACE(f) {
  for(int i=0; i<6; i++) {
  	// loop through 0-5
    // look at each face
    if(!isValueReceivedOnFaceExpired(i)) {	// is a Blink present
    
      // store the value we receive on this face
      byte neighborVal = getLastValueReceivedOnFace(i);	
      
      if(neighborVal == ACTIVE) {
      	// my neighor is in active game state
        // if my neighbor is active, then I should be active too
        gameState = ACTIVE;
      }
      //setColorOnFace(RED, i);
    }
    
  }
  
  // send our state to our neighbors
  setValueSentOnAllFaces(gameState);
  
  //
  if(gameState == ACTIVE) {
    health--;
  }
  
  // display
  if(gameState == IDLE) {
    setColor(WHITE);
  }
  else if(gameState == ACTIVE) {
    setColor(GREEN);
  }
  
}
