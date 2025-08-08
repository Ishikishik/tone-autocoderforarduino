const int speakerPin = 8;

String bnn[] = {
  "0000011",
  "1100111",
  "1011110",
  "1101110",
  "1100010",
  "1101111",
  "1100010",
  "1100110",
  "1100010",
  "1101110",
  "1011111",
};

const int bnnLength = sizeof(bnn) / sizeof(bnn[0]);

int noteTable[] = {
  196, 220, 247, 262, 294, 330, 349, 392,
  440, 494, 523, 587, 659, 698, 784, 880
};

int lengthTable[] = {100, 200, 300, 500}; // 00, 01, 10, 11

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < bnnLength; i++) {
    String byteStr = bnn[i];
    if (byteStr.length() != 7) continue;

    int isNote = byteStr.charAt(0) - '0';
    int noteBits = strtol(byteStr.substring(1, 5).c_str(), NULL, 2);
    int lenBits = strtol(byteStr.substring(5, 7).c_str(), NULL, 2);

    if (lenBits < 0 || lenBits > 3) lenBits = 0;  // 安全策
    int duration = lengthTable[lenBits];

    if (isNote == 1 && noteBits >= 0 && noteBits < sizeof(noteTable)/sizeof(noteTable[0])) {
      int freq = noteTable[noteBits];
      tone(speakerPin, freq, duration);
    } else {
      noTone(speakerPin);
    }

    delay(duration + 20);
  }

  delay(1000);
}

