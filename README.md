# sensor_lab

センサ・マイコンを使って色々遊んでいくリポジトリ。

## ディレクトリ構成

```
sensor_lab/
├── README.md                    # インデックス（このファイル）
├── sensors/
│   └── {センサ名}/
│       ├── README.md            # 型番・スペック・メモ
│       └── images/              # センサの画像
└── microcontrollers/
    └── {マイコン名}/
        ├── README.md            # 型番・スペック・メモ
        └── images/              # マイコンの画像
```

## センサ一覧

| センサ名 | 型番 | 計測対象 |
|----------|------|----------|
| [Seeed Studio RGB LED](sensors/Seeed_Studio_RGB_LED/README.md) | 104020048 | 発光（RGB LED） |
| [Seeed Studio PIR Motion Sensor](sensors/Seeed_Studio_PIR_Motion_Sensor/README.md) | 101020020 | 人体（赤外線による動体検知） |

## マイコン一覧

| マイコン名 | 型番 | メーカー |
|------------|------|----------|
| [Arduino Nano R4](microcontrollers/Arduino_Nano_R4/README.md) | ABX00087 | Arduino |

## センサREADMEのフォーマット

各センサのREADMEは以下の形式で記載する。

```markdown
# {センサ名}

| 項目 | 内容 |
|------|------|
| 型番 | |
| メーカー | |
| 個数 | |
| 計測対象 | |

## 画像
![表面](images/front.jpg)

## メモ
```

## マイコンREADMEのフォーマット

各マイコンのREADMEは以下の形式で記載する。

```markdown
# {マイコン名}

| 項目 | 内容 |
|------|------|
| 型番 | |
| メーカー | |
| 個数 | |
| クロック | |
| フラッシュ | |
| RAM | |
| インターフェース | |

## 画像
![表面](images/front.jpg)

## メモ
```
