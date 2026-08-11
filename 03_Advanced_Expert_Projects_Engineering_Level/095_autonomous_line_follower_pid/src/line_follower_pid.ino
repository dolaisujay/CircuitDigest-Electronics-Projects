// PID Line Follower Robot
float Kp = 15, Ki = 0.0, Kd = 10;
int error = 0, lastError = 0;

void loop() {
  // Read IR array sensors
  int position = readSensors();
  error = position - 2500;
  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;
  setMotorSpeeds(150 + motorSpeed, 150 - motorSpeed);
}
