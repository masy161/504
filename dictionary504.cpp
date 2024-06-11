#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// ساختار درس
struct Lesson {
    std::string name;
    std::vector<std::string> words;
    std::vector<std::string> meanings; // اضافه کردن معنی لغات
};

std::vector<Lesson> lessons;

// تابع افزودن لغت به درس
void addWordToLesson(int lessonIndex, const std::string& word, const std::string& meaning) {
    lessons[lessonIndex].words.push_back(word);
    lessons[lessonIndex].meanings.push_back(meaning); // اضافه کردن معنی لغت
}

// تابع نمایش معانی یک لغت
void showWordMeaning(const std::string& word) {
    for (const auto& lesson : lessons) {
        for (size_t i = 0; i < lesson.words.size(); ++i) {
            if (lesson.words[i] == word) {
                std::cout << "the meaning of the word " << word << ": " << lesson.meanings[i] << "\n";
                return;
            }
        }
    }
    std::cout << "the desired word was not found." << std::endl;
}

// تابع نمایش تمام لغات و معانی یک درس
void showLessonWords(int lessonIndex) {
    std::cout << "lesson words" << lessons[lessonIndex].name << ":\n";
    for (size_t i = 0; i < lessons[lessonIndex].words.size(); ++i) {
        std::cout << lessons[lessonIndex].words[i] << " - " << lessons[lessonIndex].meanings[i] << "\n";
    }
}

// تابع برگزاری امتحان
void takeExam() {
    std::cout << "----- start the test -----\n";
    std::cout << "please select a lesson:\n";
    for (size_t i = 0; i < lessons.size(); ++i) {
        std::cout << i + 1 << ". " << lessons[i].name << "\n";
    }

    int selectedLessonIndex;
    std::cout << "enter the lesson number: ";
    std::cin >> selectedLessonIndex;
    selectedLessonIndex--; // تبدیل شماره درس به ایندکس درس

    if (selectedLessonIndex >= 0 && selectedLessonIndex < lessons.size()) {
        Lesson selectedLesson = lessons[selectedLessonIndex];

        std::vector<int> indices(selectedLesson.words.size());
        for (size_t i = 0; i < indices.size(); ++i) {
            indices[i] = i;
        }
        std::random_shuffle(indices.begin(), indices.end());

        int correctAnswers = 0;
        const int numQuestions = 5;
        for (int i = 0; i < numQuestions; ++i) {
            int wordIndex = indices[i];
            std::string word = selectedLesson.words[wordIndex];
            std::string meaning = selectedLesson.meanings[wordIndex];

            std::string userAnswer;
            std::cout << "word meaning  " << word << ": ";
            std::cin >> userAnswer;

            if (userAnswer == meaning) {
                std::cout << "correct answer!\n";
                correctAnswers++;
            } else {
                std::cout << "wrong answer! correct meaning: " << meaning << "\n";
            }
        }

        std::cout << "----- end of test -----\n";
        std::cout << "number of questions answered correctly: " << correctAnswers << "/" << numQuestions << "\n";
    } else {
        std::cout << "the lesson number is invalid.\n";
    }
}

int main() { 
    Lesson lesson1;
    lesson1.name = "lesson1";
    lessons.push_back(lesson1);

    addWordToLesson(0, "Abandon", "رها کردن");
    addWordToLesson(0, "keen", "تیز ، زیرک");
    addWordToLesson(0, "Jealous", "حسود ");
    addWordToLesson(0, "Tact", "تدبیر");
    addWordToLesson(0, "Oath", "قسم ، سوگند خوردن");
    addWordToLesson(0, "Vacant", "خالی");
    addWordToLesson(0, "Hardship", "بی نوایی");
    addWordToLesson(0, "Gallant", "شجاع");
    addWordToLesson(0, "Data", "اطلاعات ، داده ها");
    addWordToLesson(0, "Unaccustomed", "غیرعادی");
    addWordToLesson(0, "Bachelor", "مرد مجرد");
    addWordToLesson(0, "Qualify", "واجد شرایط شدن");

    Lesson lesson2;
    lesson2.name = "lesson2";
    lessons.push_back(lesson2);

    addWordToLesson(1, "Corpse", "جنازه ، جسد");
    addWordToLesson(1, "Conceal", "پنهان کردن ، پوشاندن");
    addWordToLesson(1, "Dismal", "غمگین");
    addWordToLesson(1, "Frigid", "خیلی سرد");
    addWordToLesson(1, "Inhabit", "ساکن شدن");
    addWordToLesson(1, "Numb", "بی حس");
    addWordToLesson(1, "Peril", "مخاطره ، خطر");
    addWordToLesson(1, "Recline", "تکیه کردن");
    addWordToLesson(1, "Shriek", "جیغ کشیدن");
    addWordToLesson(1, "Sinister", "شیطانی");
    addWordToLesson(1, "Tempt", "وسوسه");
    addWordToLesson(1, "Wager", "شرط بندی");

    Lesson lesson3;
    lesson3.name = "lesson3";
    lessons.push_back(lesson3);

    addWordToLesson(2, "Typical", "نمونه ، معمولی");
    addWordToLesson(2, "Minimum", "حداقل");
    addWordToLesson(2, "Scarce", "کمیاب");
    addWordToLesson(2, "Annual", "سالی یکبار ، سالانه");
    addWordToLesson(2, "Persuade", "متقاعد کردن");
    addWordToLesson(2, "Essential", "ضروری");
    addWordToLesson(2, "Blend", "مخلوط کردن");
    addWordToLesson(2, "Visible", "دیدنی");
    addWordToLesson(2, "Expensive", "گران");
    addWordToLesson(2, "Talent", "استعداد");
    addWordToLesson(2, "Devise", "طراحی کردن");
    addWordToLesson(2, "Wholsale", "عمده فروشی");

    Lesson lesson4;
    lesson4.name = "lesson4";
    lessons.push_back(lesson4);

    addWordToLesson(3, "Vapor", "بخار");
    addWordToLesson(3, "Eliminate", "حذف کردن");
    addWordToLesson(3, "Villain", "آدم شرور ، مجرم");
    addWordToLesson(3, "Dense", "فشرده ، انبوه");
    addWordToLesson(3, "Utilize", "به کار بردن");
    addWordToLesson(3, "Humid", "مرطوب");
    addWordToLesson(3, "Theory", "تئوری ، نظریه");
    addWordToLesson(3, "Descend", "فرود آمدن");
    addWordToLesson(3, "Circulate", "گشتن ، دور زدن");
    addWordToLesson(3, "Enormous", "عظیم ، بزرگ");
    addWordToLesson(3, "Predict", "پیش بینی کردن");
    addWordToLesson(3, "Vanish", "ناپدید شدن");

    Lesson lesson5;
    lesson5.name = "lesson5";
    lessons.push_back(lesson5);

    addWordToLesson(4, "Tradition", "سنت");
    addWordToLesson(4, "Rural", "روستایی");
    addWordToLesson(4, "Burden", "مسئولیت سنگین");
    addWordToLesson(4, "Campus", "محوطه دانشگاه یا مدرسه");
    addWordToLesson(4, "Majority", "اکثریت");
    addWordToLesson(4, "Assemble", "تجمع ، مونتاژ کردن");
    addWordToLesson(4, "Explore", "بررسی کردن");
    addWordToLesson(4, "Topic", "موضوع");
    addWordToLesson(4, "Debate", "بحث");
    addWordToLesson(4, "Evade", "شانه خالی کردن ، فرار کردن");
    addWordToLesson(4, "Probe", "جستجو");
    addWordToLesson(4, "Reform", "اصلاح کردن");


    Lesson lesson6;
    lesson6.name = "lesson6";
    lessons.push_back(lesson6);

    addWordToLesson(5, "Approach", "نزدیک شدن");
    addWordToLesson(5, "Detect", "متوجه شدن ، کشف کردن");
    addWordToLesson(5, "Defect", "نقص");
    addWordToLesson(5, "Employee", "کارمند");
    addWordToLesson(5, "Neglect", "غفلت کردن از");
    addWordToLesson(5, "Deceive", "فریب دادن");
    addWordToLesson(5, "Undoubtedly", "بی تردید");
    addWordToLesson(5, "Popular", "عامه پسند");
    addWordToLesson(5, "Thorough", "تمام عیار");
    addWordToLesson(5, "Client", "موکل ، مشتری");
    addWordToLesson(5, "Comprehensive", "جامع ، مفصل");
    addWordToLesson(5, "Defraud", "پول گرفتن");



    Lesson lesson7;
    lesson7.name = "lesson7";
    lessons.push_back(lesson7);

    
    addWordToLesson(6, "Postpone", "به تعویق انداختن");
    addWordToLesson(6, "Consent", "رضایت دادن");
    addWordToLesson(6, "Massive", "حجیم");
    addWordToLesson(6, "Capsule", "کپسول");
    addWordToLesson(6, "Preserve", "محافظت کردن");
    addWordToLesson(6, "Denounce", "محکوم کردن ، انتقاد کردن");
    addWordToLesson(6, "Unique", "منحصر به فرد");
    addWordToLesson(6, "Torrent", "سیلاب");
    addWordToLesson(6, "Resent", "رنجیدن از");
    addWordToLesson(6, "Molest", "آسیب رساندن ، حمله کردن");
    addWordToLesson(6, "Gloomy", "تیره تار ، تاریکی");
    addWordToLesson(6, "Unforeseen", "غیر مترقبه"); 

    Lesson lesson8;
    lesson8.name = "lesson8";
    lessons.push_back(lesson8);

    
    addWordToLesson(7, "Exaggerate", "مبالغه کردن");
    addWordToLesson(7, "Amateur", "آماتور ، ناشی");
    addWordToLesson(7, "Mediocre", "معمولی");
    addWordToLesson(7, "Variety", "گوناگونی ، تنوع");
    addWordToLesson(7, "Valid", "معتبر ،‌ قانونی");
    addWordToLesson(7, "Survive", "جان سالم به در بردن");
    addWordToLesson(7, "Weird", "عجیب و غریب ،‌ مرموز");
    addWordToLesson(7, "Prominent", "مشهور ، برجسته");
    addWordToLesson(7, "Security", "امنیت ، تضمین");
    addWordToLesson(7, "Bulky", "تنومند ، چاق");
    addWordToLesson(7, "Reluctant", "ناراضی");
    addWordToLesson(7, "Obvious", "آشکار ، واضح");

    Lesson lesson9;
    lesson9.name = "lesson9";
    lessons.push_back(lesson9);

    
    addWordToLesson(8, "Vicinity", "نزدیکی ، محله");
    addWordToLesson(8, "Century", "قرن");
    addWordToLesson(8, "Rage", "خشم");
    addWordToLesson(8, "Document", "سند");
    addWordToLesson(8, "Conclude", "پایان دادن ، به نتیجه رسیدن");
    addWordToLesson(8, "Undeniable", "غیر قابل انکار");
    addWordToLesson(8, "Resist", "مقاومت کردن در برابر");
    addWordToLesson(8, "Lack", "نیاز ، نداشتن");
    addWordToLesson(8, "Ignore", "نادیده گرفتن");
    addWordToLesson(8, "Challenge", "به مبارزه طلبیدن");
    addWordToLesson(8, "Miniature", "مینیاتور ، ریز");
    addWordToLesson(8, "Source", "منشا ، منبع");
    

    Lesson lesson10;
    lesson10.name = "lesson10";
    lessons.push_back(lesson10);

    addWordToLesson(9, "Excel", "بی نظیر بودن");
    addWordToLesson(9, "Feminine", "زنانه");
    addWordToLesson(9, "Mount", "سوار شدن ، بالا رفتن");
    addWordToLesson(9, "Compete", "رقابت کردن");
    addWordToLesson(9, "Dread", "هراس ، وحشت");
    addWordToLesson(9, "Masculine", "مردانه");
    addWordToLesson(9, "Menace", "تهدید ، خطر");
    addWordToLesson(9, "Tendency", "تمایل ، گرایش");
    addWordToLesson(9, "Underestimate", "کمتر  از حد برآورد کردن");
    addWordToLesson(9, "Victorious", "فاتح ، پیروزمندانه");
    addWordToLesson(9, "Numerous", "متعدد");
    addWordToLesson(9, "Flexible", "انعطاف پذیر");


    Lesson lesson11;
    lesson11.name = "lesson11";
    lessons.push_back(lesson11);

    
    addWordToLesson(10, "Evidence", "شهادت ، گواه");
    addWordToLesson(10, "Solitary", "آدم گوشه گیر ،‌ تنها");
    addWordToLesson(10, "Vision", "دید ، خیال");
    addWordToLesson(10, "Frequent", "مکرر");
    addWordToLesson(10, "Glimpse", "نظر اجمالی");
    addWordToLesson(10, "Recent", "اخیر");
    addWordToLesson(10, "Decade", "دهه ، دوره ده ساله");
    addWordToLesson(10, "Hesitate", "مکث کردن ، اکراه داشتن");
    addWordToLesson(10, "Absurd", "پوچ");
    addWordToLesson(10, "Conflict", "اختلاف");
    addWordToLesson(10, "Minority", "اقلیت ، گروه اقلیت");
    addWordToLesson(10, "Fiction", "افسانه ، خیال");

    Lesson lesson12;
    lesson12.name = "lesson12";
    lessons.push_back(lesson12);

    
    addWordToLesson(11, "Ignite", "آتش گرفتن");
    addWordToLesson(11, "Abolish", "لغو کردن");
    addWordToLesson(11, "Urban", "شهری");
    addWordToLesson(11, "Population", "جمعیت");
    addWordToLesson(11, "Fran", "رک و راست");
    addWordToLesson(11, "Pollute", "آلوده کردن");
    addWordToLesson(11, "Reveal", "آشکار کردن");
    addWordToLesson(11, "Prohibit", "قدغن کردن");
    addWordToLesson(11, "Urgent", "فوری");
    addWordToLesson(11, "Adequate", "کافی");
    addWordToLesson(11, "Decrease", "کاهش دادن");
    addWordToLesson(11, "Audible", "قابل شنیدن ، رسا");

    Lesson lesson13;
    lesson13.name = "lesson13";
    lessons.push_back(lesson13);

    
    addWordToLesson(12, "Journalist", "روزنامه نگار");
    addWordToLesson(12, "Famine", "قحطی");
    addWordToLesson(12, "Revive", "نیروی تازه گرفتن");
    addWordToLesson(12, "Commence", "شروع کردن");
    addWordToLesson(12, "Observant", "تیز بین");
    addWordToLesson(12, "Identify", "نشان دادن هویت");
    addWordToLesson(12, "Migrate", "مهاجرت کردن");
    addWordToLesson(12, "Vessel", "کشتی ، ظرف ، آوند");
    addWordToLesson(12, "Persist", "اصرار کردن");
    addWordToLesson(12, "Hazy", "مه رقیق ، مه آلود");
    addWordToLesson(12, "Gleam", "نور ضعیف");
    addWordToLesson(12, "Editor", "ویراستار");

    Lesson lesson14;
    lesson14.name = "lesson14";
    lessons.push_back(lesson14);

    
    addWordToLesson(13, "Unruly", "عنان گسیخته ، سرکش");
    addWordToLesson(13, "Rival", "رقیب");
    addWordToLesson(13, "Violent", "خشن");
    addWordToLesson(13, "Brutal", "وحشیانه");
    addWordToLesson(13, "Opponent", "حریف ، رقیب");
    addWordToLesson(13, "Brawl", "کتک کاری");
    addWordToLesson(13, "Duplicate", "کپی کردن");
    addWordToLesson(13, "Vicious", "وحشی ، وحشیانه");
    addWordToLesson(13, "Whirling", "چرخش ، چرخیدن");
    addWordToLesson(13, "Underdog", "آدم بازنده ، توسری خور");
    addWordToLesson(13, "Thrust", "حمله کردن");
    addWordToLesson(13, "Bewildered", "سردرگم کردن");

    Lesson lesson15;
    lesson15.name = "lesson15";
    lessons.push_back(lesson15);

    
    addWordToLesson(14, "Expand", "گسترش دادن");
    addWordToLesson(14, "Alter", "اصلاح کردن");
    addWordToLesson(14, "Mature", "بالغ");
    addWordToLesson(14, "Sacred", "مقدس ، مذهبی");
    addWordToLesson(14, "Revise", "تجدید نظر کردن ، اصلاح کردن");
    addWordToLesson(14, "Pledge", "تعهد");
    addWordToLesson(14, "Casual", "اتفاقی");
    addWordToLesson(14, "Pursue", "تعقیب کردن");
    addWordToLesson(14, "Unanimous", "هم عقیده");
    addWordToLesson(14, "Fortunate", "خوش شانس");
    addWordToLesson(14, "Pioneer", "پیشگام");
    addWordToLesson(14, "Innovative", "ابتکاری");

    Lesson lesson16;
    lesson16.name = "lesson16";
    lessons.push_back(lesson16);

    
    addWordToLesson(15, "Slender", "لاغر ، کم و اندک");
    addWordToLesson(15, "Surpass", "سبقت گرفتن از");
    addWordToLesson(15, "Vast", "وسیع");
    addWordToLesson(15, "Doubt", "تردید کردن");
    addWordToLesson(15, "Capacity", "گنجایش ، ظرفیت");
    addWordToLesson(15, "Penetrate", "نفوذ کردن");
    addWordToLesson(15, "Pierce", "سوراخ کردن");
    addWordToLesson(15, "Accurate", "صحیح ، درست");
    addWordToLesson(15, "Microscope", "میکروسکوپ");
    addWordToLesson(15, "Grateful", "سپاسگزار");
    addWordToLesson(15, "Cautious", "محتاط");
    addWordToLesson(15, "Confident", "مطمئن");

    Lesson lesson17;
    lesson17.name = "lesson17";
    lessons.push_back(lesson17);

    
    addWordToLesson(16, "Appea", "علاقه");
    addWordToLesson(16, "Addict", "معتاد");
    addWordToLesson(16, "Wary", "مراقب");
    addWordToLesson(16, "Aware", "آگاه ، دانا");
    addWordToLesson(16, "Misfortune", "بدشانس");
    addWordToLesson(16, "Avoid", "اجتناب کردن");
    addWordToLesson(16, "Wretched", "فلاکت بار");
    addWordToLesson(16, "Keg", "بشکه کوچک");
    addWordToLesson(16, "Nouris", "تغذیه کردن");
    addWordToLesson(16, "Harsh", "تند");
    addWordToLesson(16, "Quantity", "مقدار");
    addWordToLesson(16, "Opt", "انتخاب کردن");


    Lesson lesson18;
    lesson18.name = "lesson18";
    lessons.push_back(lesson18);

    
    addWordToLesson(17, "Tragedy", "تراژدی");
    addWordToLesson(17, "Pedestrian", "عابر پیاده");
    addWordToLesson(17, "Glance", "نگاه گذرا ، نگاهی انداختن");
    addWordToLesson(17, "Budget", "بودجه");
    addWordToLesson(17, "Nimble", "چابک ، فرز");
    addWordToLesson(17, "Manipulate", "دستکاری کردن");
    addWordToLesson(17, "Reckless", "بی احتیاط");
    addWordToLesson(17, "Horrid", "ترسناک ، مهیب");
    addWordToLesson(17, "Rave", "هذیان گفتن");
    addWordToLesson(17, "Economical", "مقرون به صرفه");
    addWordToLesson(17, "Lubricate", "روغن کاری کردن");
    addWordToLesson(17, "Ingenious", "مبتکر");

    Lesson lesson19;
    lesson19.name = "lesson19";
    lessons.push_back(lesson19);

    
    addWordToLesson(18, "Harvest", "درو کردن");
    addWordToLesson(18, "Abundant", "فراوان");
    addWordToLesson(18, "Uneasy", "ناراحت");
    addWordToLesson(18, "Calculate", "محاسبه کردن");
    addWordToLesson(18, "Absorb", "جذب کردن رطوبت یا آب");
    addWordToLesson(18, "Estimate", "محاسبه کردن ، قضاوت");
    addWordToLesson(18, "Morsel", "لقمه");
    addWordToLesson(18, "Quota", "سهمیه");
    addWordToLesson(18, "Threat", "تهدید ، خطر");
    addWordToLesson(18, "Ban", "منع کردن ، ممنوع کردن");
    addWordToLesson(18, "Panic", "سراسیمگی ، هول");
    addWordToLesson(18, "Appropriate", "مناسب ، درست");

    Lesson lesson20;
    lesson20.name = "lesson20";
    lessons.push_back(lesson20);


    
    addWordToLesson(19, "Emerge", "بیرون آمدن");
    addWordToLesson(19, "Jagged", "دندانه دار");
    addWordToLesson(19, "Linger", "باقی ماندن ، طول کشیدن");
    addWordToLesson(19, "Ambush", "شبیخون زدن");
    addWordToLesson(19, "Crafty", "ماهر ، حرفه ای");
    addWordToLesson(19, "Defiant", "نافرمان");
    addWordToLesson(19, "Vigor", "قدرت ، توان");
    addWordToLesson(19, "Perish", "هلاک شدن");
    addWordToLesson(19, "Fragile", "شکستنی");
    addWordToLesson(19, "Captive", "اسیر جنگی ، محبوس");
    addWordToLesson(19, "Prosper", "رونق گرفتن");
    addWordToLesson(19, "Devour", "بلعیدن ، از چیزی مملو بودن");

    Lesson lesson21;
    lesson21.name = "lesson21";
    lessons.push_back(lesson21);

    
    addWordToLesson(20, "Plea", "تقاضا");
    addWordToLesson(20, "Weary", "خسته");
    addWordToLesson(20, "Collide", "تصادف کردن");
    addWordToLesson(20, "Confirm", "تتایید کردن");
    addWordToLesson(20, "Verify", "درباره ی صحت چیزی تحقیق کردن");
    addWordToLesson(20, "Anticipate", "انتظار داشتن");
    addWordToLesson(20, "Dilemma", "دوراهی ، تنگنا");
    addWordToLesson(20, "Detour", "راه انحرافی	");
    addWordToLesson(20, "Merit", "شایستگی");
    addWordToLesson(20, "Transmit", "انتقال دادن");
    addWordToLesson(20, "Relieve", "تسکین دادن درد");
    addWordToLesson(20, "Baffle", "سر در گم کردن");

    Lesson lesson22;
    lesson22.name = "lesson22";
    lessons.push_back(lesson22);

    
    addWordToLesson(21, "Warden", "مسئول ، نگهبان");
    addWordToLesson(21, "Acknowledge", "پذیرفتن ، به رسمیت شناختن");
    addWordToLesson(21, "Justice", "عدالت");
    addWordToLesson(21, "Delinquent", "بزهکار");
    addWordToLesson(21, "Reject", "نپذیرفتن");
    addWordToLesson(21, "Deprive", "محروم کردن از");
    addWordToLesson(21, "Spouse", "همسر");
    addWordToLesson(21, "Vocation", "حرفه");
    addWordToLesson(21, "Unstable", "ناپایدار ، متزلزل");
    addWordToLesson(21, "Homicide", "قتل ، قاتل");
    addWordToLesson(21, "Penalize", "اجحاف کردن ، ظلم کردن");
    addWordToLesson(21, "Beneficiary", "ذینفع ،‌ بهره مند");

    Lesson lesson23;
    lesson23.name = "lesson23";
    lessons.push_back(lesson23);


    addWordToLesson(22, "Reptile", "جانور خزنده");
    addWordToLesson(22, "Rerely", "به ندرت");
    addWordToLesson(22, "Forbid", "ممنوع کردن");
    addWordToLesson(22, "Logical", "منطقی");
    addWordToLesson(22, "Exhibit", "به نمایش گذاشتن");
    addWordToLesson(22, "Proceed", "پیش رفتن");
    addWordToLesson(22, "Precaution", "احتیاط");
    addWordToLesson(22, "Extract", "بیرون کشیدن");
    addWordToLesson(22, "Prior", "قبلی ، قبل از");
    addWordToLesson(22, "Embrace", "آغوش ، بغل");
    addWordToLesson(22, "Valiant", "شجاع");
    addWordToLesson(22, "Partial", "نسبی ، نا تمام");

    Lesson lesson24;
    lesson24.name = "lesson24";
    lessons.push_back(lesson24);

    
    addWordToLesson(23, "Fierce", "خشن و وحشی");
    addWordToLesson(23, "Detest", "متنفر بودن");
    addWordToLesson(23, "Sneer", "ریشخند کردن");
    addWordToLesson(23, "Scowl", "اخم کردن");
    addWordToLesson(23, "Encourage", "تشویق کردن");
    addWordToLesson(23, "Consider", "درباره چیزی فکر کردن");
    addWordToLesson(23, "Vermin", "آفات جانوری");
    addWordToLesson(23, "Wail", "شیون کردن");
    addWordToLesson(23, "Symbol", "نماد");
    addWordToLesson(23, "Authority", "قدرت ، مقتدر");
    addWordToLesson(23, "Neutral", "بی طرف");
    addWordToLesson(23, "Trifle", "امر جزئی");

    Lesson lesson25;
    lesson25.name = "lesson25";
    lessons.push_back(lesson25);

    
    addWordToLesson(24, "Architect", "معمار");
    addWordToLesson(24, "Matrimony", "ازدواج");
    addWordToLesson(24, "Baggage", "اسباب سفر");
    addWordToLesson(24, "Squander", "ضایع کردن");
    addWordToLesson(24, "Abroad", "به کشور دیگر ، خارج از کشور");
    addWordToLesson(24, "Fugitive", "فراری");
    addWordToLesson(24, "Calamity", "مصیبت");
    addWordToLesson(24, "Pauper", "فقیر ، مسکین");
    addWordToLesson(24, "Envy", "حسادت ، حسادت ورزیدن");
    addWordToLesson(24, "Collapse", "فروپاشی ، شکست");
    addWordToLesson(24, "Prosecute", "وکالت شاکی را به عهده گرفتن");
    addWordToLesson(24, "Bigamy", "داشتن دو همسر همزمان");

    Lesson lesson26;
    lesson26.name = "lesson26";
    lessons.push_back(lesson26);

    
    addWordToLesson(25, "Possible", "احتمال ، ‌امکان");
    addWordToLesson(25, "Compel", "مجبور کردن");
    addWordToLesson(25, "Awkward", "دست و پا چلفتی ، شرمسارانه");
    addWordToLesson(25, "Venture", "به خطر انداختن ، جرات کردن");
    addWordToLesson(25, "Awesome", "ترسناک ، عالی");
    addWordToLesson(25, "Guide", "راهنما");
    addWordToLesson(25, "Quench", "خاموش کردن ، عطش را فرو نشاندن");
    addWordToLesson(25, "Betray", "نارو زدن ، لو دادن");
    addWordToLesson(25, "Utter", "بر زبان آوردن");
    addWordToLesson(25, "Pacify", "آرام کردن");
    addWordToLesson(25, "Respond", "پاسخ دادن ، واکنش نشان دادن");
    addWordToLesson(25, "Beckon", "با اشاره فرا خواندن");

    Lesson lesson27;
    lesson27.name = "lesson27";
    lessons.push_back(lesson27);

    
    addWordToLesson(26, "Despite", "بر خلاف ، با وجود اینکه");
    addWordToLesson(26, "Disrupt", "متلاشی کردن");
    addWordToLesson(26, "Rash", "جوش ، عجولانه");
    addWordToLesson(26, "Rapid", "سریع");
    addWordToLesson(26, "Exhaust", "تا ته مصرف کردن ، خسته کردن");
    addWordToLesson(26, "Severity", "شدت");
    addWordToLesson(26, "Feeble", "ضعیف");
    addWordToLesson(26, "Unite", "متحد کردن ، یکی کردن");
    addWordToLesson(26, "Cease", "متوقف کردن");
    addWordToLesson(26, "Thrifty", "صرفه جو");
    addWordToLesson(26, "Miserly", "خسیس");
    addWordToLesson(26, "Monarch", "فرمانروای مطلق");

    Lesson lesson28;
    lesson28.name = "lesson28";
    lessons.push_back(lesson28);

    
    addWordToLesson(27, "Outlaw", "قانون شکن");
    addWordToLesson(27, "Promote", "ترفیع دادن ، ایجاد کردن");
    addWordToLesson(27, "Undernourished", "سوء تغذیه");
    addWordToLesson(27, "Illustrate", "با مثال توضیح دادن");
    addWordToLesson(27, "Disclose", "فاش کردن");
    addWordToLesson(27, "Excessive", "بیش از حد");
    addWordToLesson(27, "Disaster", "فاجعه");
    addWordToLesson(27, "Censor", "سانسورچی ، سانسور کردن");
    addWordToLesson(27, "Culprit", "مجرم");
    addWordToLesson(27, "Juvenile", "نوجوان");
    addWordToLesson(27, "Bait", "طعمه");
    addWordToLesson(27, "Insist", "تاکید کردن ، اصرار کردن");

    Lesson lesson29;
    lesson29.name = "lesson29";
    lessons.push_back(lesson29);


    addWordToLesson(28, "Toil", "زحمت");
    addWordToLesson(28, "Blunder", "اشتباه بزرگ ، اشتباه کردن");
    addWordToLesson(28, "Daze", "مبهوت کردن");
    addWordToLesson(28, "Mourn", "سوگواری کردن");
    addWordToLesson(28, "Subside", "فروکشی کردن");
    addWordToLesson(28, "Maim", "علیل کردن");
    addWordToLesson(28, "Comprehend", "قهمیدن");
    addWordToLesson(28, "Commend", "تحسین کردن");
    addWordToLesson(28, "Final", "نهایی ، قطعی");
    addWordToLesson(28, "Exempt", "معاف کردن ، معاف");
    addWordToLesson(28, "Vain", "مغرور ، بیهوده");
    addWordToLesson(28, "Repetition", "تکرار");


    Lesson lesson30;
    lesson30.name = "lesson30";
    lessons.push_back(lesson30);

    
    addWordToLesson(29, "Depict", "تصویر کردن ، شرح دادن");
    addWordToLesson(29, "Motal", "فناپذیر ، مهلک");
    addWordToLesson(29, "Novel", "نوین ، جدید ، رمان");
    addWordToLesson(29, "Occupant", "ساکن ، مقیم");
    addWordToLesson(29, "Appoint", "منصوب کردن ، مقرر کردن");
    addWordToLesson(29, "Quarter", "محل سکونت ، اسکان دادن");
    addWordToLesson(29, "Site", "محل");
    addWordToLesson(29, "Quote", "نقل قول کردن ، قیمت دادن");
    addWordToLesson(29, "Verse", "آیه ، بیت	");
    addWordToLesson(29, "Morality", "اخلاقیات");
    addWordToLesson(29, "Roam", "پرسه زدن");
    addWordToLesson(29, "Attract", "جذب کردن");

    Lesson lesson31;
    lesson31.name = "lesson31";
    lessons.push_back(lesson31);

    
    addWordToLesson(30, "Commuter", "مسافر هر روزه");
    addWordToLesson(30, "Confine", "محبوس کردن");
    addWordToLesson(30, "Idle", "بیکار ، تنبل");
    addWordToLesson(30, "Idol", "بت ، محبوب");
    addWordToLesson(30, "Jest", "شوخی کردن ، شوخی");
    addWordToLesson(30, "Patriotic", "میهنی ، میهن پرستانه");
    addWordToLesson(30, "Dispute", "مخالفت ، جر و بحث");
    addWordToLesson(30, "Valor", "شجاعت");
    addWordToLesson(30, "Lunatic", "احمق");
    addWordToLesson(30, "Vein", "سیاهرگ ، رگه");
    addWordToLesson(30, "Uneventful", "بی حادثه ، بدون رویداد مهم");
    addWordToLesson(30, "Fertile", "بارور شده ، حاصلخیز");

    Lesson lesson32;
    lesson32.name = "lesson32";
    lessons.push_back(lesson32);

    
    addWordToLesson(31, "Refer", "اشاره کردن ، ارجاع کردن");
    addWordToLesson(31, "Distress", "درماندگی ،‌ مخمصه");
    addWordToLesson(31, "Diminish", "کاهش دادن ، تضعیف کردن");
    addWordToLesson(31, "Maximum", "حداکثر");
    addWordToLesson(31, "Flee", "فرار کردن");
    addWordToLesson(31, "Vulnerable", "آسیب پذیر ، حساس");
    addWordToLesson(31, "Signify", "معنی دادن ، مهم بودن");
    addWordToLesson(31, "Mythology", "اسطوره شناسی");
    addWordToLesson(31, "Colleague", "همکار");
    addWordToLesson(31, "Torment", "درد و رنج ، عذاب دادن");
    addWordToLesson(31, "Provide", "تامین کردن");
    addWordToLesson(31, "Loyalty", "وفاداری");

    Lesson lesson33;
    lesson33.name = "lesson33";
    lessons.push_back(lesson33);

    
    addWordToLesson(32, "Volunteer", "داوطلب");
    addWordToLesson(32, "Prejudice", "پیش داوری ، لطمه");
    addWordToLesson(32, "Shrill", "گوش خراش");
    addWordToLesson(32, "Jolly", "شاد ، خوش");
    addWordToLesson(32, "Witty", "شوخ");
    addWordToLesson(32, "Hinder", "به تاخیر انداختن");
    addWordToLesson(32, "Lecture", "تدریس ، نصیحت");
    addWordToLesson(32, "Abuse", "خشونت کردن ، سوء استفاده کردن");
    addWordToLesson(32, "Mumble", "من من کردن");
    addWordToLesson(32, "Mute", "خاموش ، بی صدا");
    addWordToLesson(32, "Wad", "گلوله پنبه ، دسته");
    addWordToLesson(32, "Retain", "حفظ کردن ، وکیل گرفتن");

    Lesson lesson34;
    lesson34.name = "lesson34";
    lessons.push_back(lesson34);

    
    addWordToLesson(33, "Candidate", "کاندیدا ، نامزد");
    addWordToLesson(33, "Precede", "مقدم بودن بر");
    addWordToLesson(33, "Adolescent", "نوجوان");
    addWordToLesson(33, "Coeducational", "مدرسه یا دانشگاه مختلط");
    addWordToLesson(33, "Radical", "ریشه ای ، افراطی ، تندرو");
    addWordToLesson(33, "pontaneous", "خودبخود ،‌خودجوش");
    addWordToLesson(33, "Skim", "از روی چیزی گذشتن");
    addWordToLesson(33, "Vaccinate", "واکسن زدن");
    addWordToLesson(33, "Untidy", "نامرتب");
    addWordToLesson(33, "Utensil", "ابزار");
    addWordToLesson(33, "Sensitive", "حساس ، زود رنج");
    addWordToLesson(33, "Temperate", "معتدل");

    Lesson lesson35;
    lesson35.name = "lesson35";
    lessons.push_back(lesson35);

    
    addWordToLesson(34, "Vague", "مبهم ، دو پهلو");
    addWordToLesson(34, "Elevate", "بلند کردن ، ارتقاع دادن");
    addWordToLesson(34, "Lottery", "بخت آزمایی");
    addWordToLesson(34, "Finance", "امور مالی");
    addWordToLesson(34, "Obtain", "به دست آوردن");
    addWordToLesson(34, "Cinema", "سینما");
    addWordToLesson(34, "Event", "اتفاق ، مسابقه");
    addWordToLesson(34, "Discard", "دور انداختن");
    addWordToLesson(34, "Soar", "اوج گرفتن");
    addWordToLesson(34, "Subsequent", "بعدی");
    addWordToLesson(34, "Relate", "گفتن ، ربط دادن");
    addWordToLesson(34, "Stationary", "ثابت");

    Lesson lesson36;
    lesson36.name = "lesson36";
    lessons.push_back(lesson36);

    
    addWordToLesson(35, "Prompt", "باعث شدن");
    addWordToLesson(35, "Hasty", "شتابزده ،‌عجول");
    addWordToLesson(35, "Scorch", "جای سوختگی");
    addWordToLesson(35, "Tempest", "توفان");
    addWordToLesson(35, "Soothe", "آرام کردن ، تسکین دادن");
    addWordToLesson(35, "Sympathetic", "همدرد");
    addWordToLesson(35, "Redeem", "باز خریدن ، جبران کردن");
    addWordToLesson(35, "Resume", "از سر گرفتن");
    addWordToLesson(35, "Harmony", "سازگار");
    addWordToLesson(35, "Refrain", "برگردان ، خودداری کردن");
    addWordToLesson(35, "Illegal", "بر خلاف قانون");
    addWordToLesson(35, "Narcotic", "ماده مخدر");

    Lesson lesson37;
    lesson37.name = "lesson37";
    lessons.push_back(lesson37);

    
    addWordToLesson(36, "Heir", "وارث");
    addWordToLesson(36, "Majestic", "با عظمت");
    addWordToLesson(36, "Dwindle", "به تدریج ضعیف شدن");
    addWordToLesson(36, "Surplus", "مازاد");
    addWordToLesson(36, "Traitor", "خائن");
    addWordToLesson(36, "Deliberate", "تعمق کردن");
    addWordToLesson(36, "Vandal", "آدم خرابکار");
    addWordToLesson(36, "Drought", "خشکسالی");
    addWordToLesson(36, "Abide", "تحمل کردن");
    addWordToLesson(36, "Unify", "با هم متحد شدن");
    addWordToLesson(36, "Summit", "اوج ، قله");
    addWordToLesson(36, "Heed", "توجه کردن به");

    Lesson lesson38;
    lesson38.name = "lesson38";
    lessons.push_back(lesson38);

    
    addWordToLesson(37, "Biography", "شرح حال");
    addWordToLesson(37, "Drench", "خیس کردن");
    addWordToLesson(37, "Swarm", "گله");
    addWordToLesson(37, "Wobble", "لرزیدن ، لرزش");
    addWordToLesson(37, "Tumult", "غوغا");
    addWordToLesson(37, "Kneel", "زانو زدن");
    addWordToLesson(37, "Dejected", "افسرده");
    addWordToLesson(37, "Obedient", "مطیع");
    addWordToLesson(37, "Recede", "عقب رفتن");
    addWordToLesson(37, "Tyrant", "ظالم");
    addWordToLesson(37, "Charity", "صدقه ، بخشش ، خیریه");
    addWordToLesson(37, "Verdict", "رای ، عقیده");

    Lesson lesson39;
    lesson39.name = "lesson39";
    lessons.push_back(lesson39);

    
    addWordToLesson(38, "Unearth", "از زیر خاک بیرون کشیدن");
    addWordToLesson(38, "Depart", "ترک کردن ، فوت کردن");
    addWordToLesson(38, "Coincide", "همزمان بودن");
    addWordToLesson(38, "Cancel", "باطل کردن");
    addWordToLesson(38, "Debtor", "بدهکار");
    addWordToLesson(38, "Legible", "خوانا");
    addWordToLesson(38, "Placard", "پلاکارد");
    addWordToLesson(38, "Contagious", "مسری ، واگیر");
    addWordToLesson(38, "Clergy", "روحانیت");
    addWordToLesson(38, "Customary", "مرسوم ،‌رایج");
    addWordToLesson(38, "Transparent", "واضح ،‌شفاف");
    addWordToLesson(38, "Scald", "سوزاندن ، سوختگی");

    Lesson lesson40;
    lesson40.name = "lesson40";
    lessons.push_back(lesson40);

    
    addWordToLesson(39, "Epidemic", "همه گیر");
    addWordToLesson(39, "Obesity", "فربهی ، چاقی");
    addWordToLesson(39, "Magnify", "بزرگ کردن");
    addWordToLesson(39, "Chiropractor", "پزشک متخصص دست یا پا");
    addWordToLesson(39, "Obstacle", "مانع");
    addWordToLesson(39, "Ventilate", "تهویه");
    addWordToLesson(39, "Jeopardize", "به خطر انداختن");
    addWordToLesson(39, "Negative", "منفی");
    addWordToLesson(39, "Pension", "مستمری ، حقوق بازنشستگی");
    addWordToLesson(39, "Vital", "ضروری ، حیاتی");
    addWordToLesson(39, "Municipal", "مربوط به شهرداری ، شهری");
    addWordToLesson(39, "Oral", "شفاهی ، دهانی");

    Lesson lesson41;
    lesson41.name = "lesson41";
    lessons.push_back(lesson41);

    
    addWordToLesson(40, "Complacent", "از خود راضی");
    addWordToLesson(40, "Wasp", "زنبور بدون عسل");
    addWordToLesson(40, "Rehabilitate", "توان بخشیدن ،‌بازسازی کردن");
    addWordToLesson(40, "Parole", "آزادی مشروط ، قول شرف");
    addWordToLesson(40, "Vertical", "عمودی");
    addWordToLesson(40, "Multitude", "فراوانی ، جمعیت");
    addWordToLesson(40, "Nominate", "نامزد مقامی کردن");
    addWordToLesson(40, "Potential", "بالقوه");
    addWordToLesson(40, "Morgue", "سردخانه");
    addWordToLesson(40, "Preoccupied", "مشغول و نگران");
    addWordToLesson(40, "Upholstery", "رویه");
    addWordToLesson(40, "Indifference", "بی توجهی");

    Lesson lesson42;
    lesson42.name = "lesson42";
    lessons.push_back(lesson42);
    
    
    addWordToLesson(41, "Maintain", "حفظ کردن ، تامین کردن");
    addWordToLesson(41, "Snub", "بی اعتنایی کردن");
    addWordToLesson(41, "Endure", "تحمل کردن ، دوام آوردن");
    addWordToLesson(41, "Wrath", "خشم");
    addWordToLesson(41, "Expose", "فاش کردن");
    addWordToLesson(41, "Legend", "افسانه ،‌اسطوره");
    addWordToLesson(41, "Ponder", "به فکر فرو رفتن");
    addWordToLesson(41, "Resign", "استعفا دادن ، تسلیم شدن");
    addWordToLesson(41, "Drastic", "اساسی ، بنیادی");
    addWordToLesson(41, "Wharf", "اسکله");
    addWordToLesson(41, "Amend", "اصلاح کردن");
    addWordToLesson(41, "ballot", "برگه رای");

    

    std::cout << "choose the word , lesson or test :\n";
    std::cout << "1. show the meaning of the word: \n";
    std::cout << "2. showing the words of a lesson: \n";
    std::cout << "3. start the test: \n";
    std::cout << "enter the option: ";

    int option;
    std::cin >> option;

    if (option == 1) {
        std::string word;
        std::cout << "enter the word: ";
        std::cin >> word;
        showWordMeaning(word);
    } else if (option == 2) {
        std::cout << "please select a lesson:\n";
        for (size_t i = 0; i < lessons.size(); ++i) {
            std::cout << i + 1 << ". " << lessons[i].name << "\n";
        }

int selectedLessonIndex;
        std::cout << "enter the lesson number: ";
        std::cin >> selectedLessonIndex;
        selectedLessonIndex--; // تبدیل شماره درس به ایندکس درس

        if (selectedLessonIndex >= 0 && selectedLessonIndex < lessons.size()) {
            showLessonWords(selectedLessonIndex);
        } else {
            std::cout << "the lesson number is  invalid.\n";
        }
    } else if (option == 3) {
        takeExam();
    } else {
        std::cout << "the option is invalid.\n";
    }
    
    return 0;
}