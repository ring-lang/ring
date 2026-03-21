# 🌍 FlatEarth-Ring

<div align="center">

![Ring Language](https://img.shields.io/badge/Language-Ring-blue?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Version](https://img.shields.io/badge/Version-1.0.0-orange?style=for-the-badge)

**نموذج الأرض المسطحة - حركة الشمس والقمر**  
**Flat Earth Model - Sun & Moon Motion**  
**Modèle Terre Plate - Mouvement Soleil & Lune**

</div>

---

## 📖 Description | الوصف | Description

An interactive simulation of the **Flat Earth model** built with the [Ring programming language](https://ring-lang.github.io), featuring real-time animation of the Sun and Moon orbiting above a flat Earth disc.

نموذج تفاعلي للأرض المسطحة مبني بلغة البرمجة **Ring**، يعرض حركة الشمس والقمر فوق الأرض المسطحة مع التقويم الهجري الدقيق.

---

## ✨ Features | المميزات | Fonctionnalités

| Feature | الميزة | Fonctionnalité |
|---------|--------|----------------|
| 🌞 Animated Sun orbit with rays | مدار الشمس المتحرك مع الأشعة | Orbite solaire animée |
| 🌙 Realistic Moon phases (Hijri calendar) | مراحل القمر الواقعية (التقويم الهجري) | Phases lunaires réalistes |
| 🌑 Day/Night shadow zones | مناطق الليل والنهار | Zones jour/nuit |
| 📅 Accurate Gregorian ↔ Hijri conversion | تحويل دقيق ميلادي ↔ هجري | Conversion grégorien ↔ hégirien |
| 🌐 3 Languages: EN \| AR \| FR | 3 لغات: إنجليزي \| عربي \| فرنسي | 3 langues: EN \| AR \| FR |
| ⏰ Real-time clock from system | ساعة حية من النظام | Horloge en temps réel |
| 📍 Location display | عرض الموقع الجغرافي | Affichage de localisation |
| 🔄 Adjustable animation speed | سرعة متعددة للحركة | Vitesse d'animation réglable |
| 📆 Navigate by day/month/season | التنقل بالأيام/الشهور/الفصول | Navigation jour/mois/saison |
| 🔭 Eclipse detection | كشف الكسوف والخسوف | Détection des éclipses |
| ↔️ Resizable window | نافذة قابلة للتغيير | Fenêtre redimensionnable |

---

## 🖼️ Screenshot | لقطة الشاشة

```
┌─────────────────────────────┬────────────────────────┐
│                             │   Control Panel        │
│    🌌 Flat Earth Map 🌌     │   📅 Date Information  │
│                             │   🔭 Orbit Information │
│   ⭐ . * . ⭐ . * . ⭐      │   🌙 Moon Phase        │
│                             │   🗓️ Select Season     │
│      [Antarctica ring]      │   🧭 Navigation        │
│    /  Continents  \         │   🎮 Controls          │
│   |   🌞  🌙       |        │   🌐 Language: EN|AR|FR│
│    \              /         │   ⏰ 14:32:05          │
│      [N. Pole]              │   📍 Adrar, Algeria    │
│                             │                        │
└─────────────────────────────┴────────────────────────┘
```

---

## 📁 Project Structure | هيكل المشروع

```
FlatEarth-Ring/
├── main.ring              # Entry point - UI & window setup
├── functions.ring         # Core logic & drawing functions
├── globals.ring           # Global variables & language data
├── constants.ring         # Constants (PI, orbits, seasons)
├── colors.ring            # Color definitions
├── pens_brushes_fonts.ring # Drawing tools
└── README.md              # This file
```

---

## 🚀 Requirements | المتطلبات | Prérequis

- **Ring Language** >= 1.20  
  Download: [ring-lang.github.io](https://ring-lang.github.io)
- **RingQt** library (included with Ring)
- **lightguilib.ring** (included with Ring)

---

## ▶️ How to Run | كيفية التشغيل | Comment exécuter

```bash
# Clone the repository
git clone https://github.com/eternel0422/FlatEarth-Ring.git

# Navigate to project folder
cd FlatEarth-Ring

# Run with Ring
ring main.ring
```

Or simply double-click `main.ring` if Ring is associated with `.ring` files.

---

## 🎮 Controls | أزرار التحكم | Contrôles

| Button | Action |
|--------|--------|
| **Previous/Next Day** | Navigate one day at a time |
| **Prev/Next Month** | Jump by one month |
| **Select Season** | Jump directly to a season |
| **Day/Night** | Toggle shadow zones on/off |
| **Orbit Info** | Show/hide orbit radius info |
| **Moon Speed** | Slow / Medium / Fast |
| **Pause/Resume** | Stop/start animation |
| **Speed** | 0.1x → 0.25x → 0.5x → 1x → 2x → 5x |
| **Reset** | Return to today's date (20 Mar 2026) |
| **Language** | Switch EN → AR → FR → EN |

---

## 🌙 Hijri Calendar | التقويم الهجري

The app uses an accurate **Gregorian → Hijri conversion algorithm** (Faris method via Julian Day Number):

- Reference point: **20 March 2026 = 1 Ramadan 1447 H**
- Accurate for any date range
- Hijri month names in 3 languages

---

## 🗺️ Flat Earth Model

The simulation follows the classic flat Earth model:

- **North Pole** at the center
- **Antarctica** as an outer protective ring
- **Sun** orbits above at radius ~120 units (varies by season)
- **Moon** orbits above at radius ~190 units
- **Day/Night** determined by Sun position (lantern model)
- Sun orbit expands in summer, contracts in winter

---

## 👨‍💻 Developer | المطور | Développeur

- **GitHub:** [@eternel0422](https://github.com/eternel0422)
- **Language:** [Ring](https://ring-lang.github.io) — Created by **Mahmoud Samir Fayed**
- **Built with:** Claude AI (Anthropic) assistance

---

## 🤝 Contributing | المساهمة

Contributions are welcome! Feel free to:
- Report bugs via [Issues](https://github.com/eternel0422/FlatEarth-Ring/issues)
- Submit improvements via [Pull Requests](https://github.com/eternel0422/FlatEarth-Ring/pulls)

---

## 📄 License | الرخصة

This project is licensed under the **MIT License** — see [LICENSE](LICENSE) for details.

---

<div align="center">

Made with ❤️ using [Ring Language](https://ring-lang.github.io)

**"وَإِلَى الْأَرْضِ كَيْفَ سُطِحَتْ"**  
*(Al-Ghashiyah: 20)*

</div>
