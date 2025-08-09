// {周波数, 長さ(ミリ秒)} のペアを格納
float melody[][2] = {
    // 1小節目
    {330,500},{392,500},{659,500},{523,500},{587,500},{784,500}
};

const int speakerPin = 11;  // スピーカーを接続するピン
const float noteDuration = 0.2; // 音符の長さ倍率（100ms基準）
const float noteWave = 2;     // 音の高さ倍率（周波数に掛ける倍率）

const int melodyLength = sizeof(melody) / sizeof(melody[0]);

void setup() {
  pinMode(speakerPin, OUTPUT);

  // 音の長さを調整
  if (noteDuration != 1.0) {
    for (int i = 0; i < melodyLength; i++) {
      melody[i][1] *= noteDuration; // 長さは index 1
    }
  }

  // 音の高さを調整
  if (noteWave != 1.0) {
    for (int i = 0; i < melodyLength; i++) {
      melody[i][0] *= noteWave; // 周波数は index 0
    }
  }
}

void loop() {
  for (int i = 0; i < melodyLength; i++) {
    float freq = melody[i][0];
    float dur = melody[i][1];

    if (freq > 0) { // 休符ではない場合
      tone(speakerPin, freq);
      delay(dur);
    } else { // 休符（freq = 0）なら無音
      noTone(speakerPin);
      delay(dur);
    }
  }
noTone(speakerPin);
delay(1000);
}