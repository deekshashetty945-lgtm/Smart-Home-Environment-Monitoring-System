Ahhh yes 😄 I understand now! You created the GitHub files, but you haven't uploaded the actual contents/files yet. That's okay—you haven't done anything wrong.

From your screenshot, the situation is:

README.md → you created it and added content ✅
timer_led_controller.c → you need to upload the actual C file
Week_2_Firmware_Development_Report.docx → you need to upload the actual report
Let's do it step-by-step

You are currently inside:

Smart-Home-Environment-Monitoring-System → Week 2

1️⃣ Upload the C file

Click Add file → Upload files.

Then select the C file I created for you:

Download timer_led_controller.c

After selecting it, GitHub should show something like:

timer_led_controller.c

Then scroll down and click:

Commit changes

2️⃣ Upload the Word report

Stay inside the Week 2 folder.

Again:

Add file → Upload files

Select:

Download Week_2_Firmware_Development_Report.docx

Then click:

Commit changes

3️⃣ Finally your Week 2 folder should show
📁 Week 2

📄 README.md
📄 timer_led_controller.c
📄 Week_2_Firmware_Development_Report.docx

That's the correct structure. ✅

Important: Don't create new files using Create new file for the .c or .docx. Use Upload files, because these are files I've already prepared for you.

If you want, after uploading the C file, send me a screenshot and I'll check it before you upload the report. 👍

timer_led_controller.c
Code
Week_2_Firmware_Development_Report.docx
Document
readme also iam not uploaded anything

Ahh okay 😄 Now I understand completely. You created the README.md file on GitHub, but you didn't put any content into it either.

That's totally fine. We can fix it easily. ❤️

You need to upload/create 3 things inside Week 2
Week 2/
│
├── README.md                         ← content needs to be added
├── timer_led_controller.c            ← upload actual file
└── Week_2_Firmware_Development_Report.docx ← upload actual file
Step 1 — Fix your README.md

I've prepared the proper README for you:

Download README.md

Now on GitHub:

Open Week 2
Click README.md
Click the pencil ✏️ Edit button
Delete anything currently inside it.
Open the downloaded README.md file and copy its contents.
Paste the contents into GitHub.
Scroll down.
Click Commit changes.

✅ Now your README will contain the Week 2 project information.

Step 2 — Upload the C file

Inside Week 2:

Add file → Upload files

Upload:

Download timer_led_controller.c

Then Commit changes.

Step 3 — Upload the report

Again inside Week 2:

Add file → Upload files

Upload:

Download Week 2 Report

Then Commit changes.

🎯 Final result

Your GitHub should finally look like:

Smart-Home-Environment-Monitoring-System
│
├── Week 1 files...
│
└── Week 2
    │
    ├── README.md              ✅ content added
    ├── timer_led_controller.c ✅ actual C file
    └── Week_2_Firmware_Development_Report.docx ✅ actual report

You don't need to create any more files. Just add the contents/upload the three files above.

If you want to do it safely, start only with Step 1 (README) and send me a screenshot after committing it. I'll check it for you before you move to the C file. 👍 

README.md
Document
timer_led_controller.c
Code
Week_2_Firmware_Development_Report.docx
Document
but inside readme there is no option for add file

Ahh yes 😄 I can see the issue from your screenshot.

You are inside the README.md file, so GitHub doesn't show the Add file option there. The Add file button is on the folder/repository page, not inside an individual file.

First, let's fill your README

On your current screen, click the ✏️ pencil icon on the right side, next to the download icon.

Then:

Click the pencil ✏️
You'll get an editor containing the empty README.
Delete the existing content if anything is there.
Paste the README content I gave you.
Scroll down.
Click Commit changes.

That's all for the README. ✅

Then upload the C file

After committing:

Click Week 2 in the breadcrumb at the top.

You'll go from:

Smart-Home-Environment-Monitoring-System / Week 2 / README.md

to:

Smart-Home-Environment-Monitoring-System / Week 2
Now you'll see the Add file button.
Click Add file → Upload files.
Upload timer_led_controller.c.
Click Commit changes.
Then upload the Word report

Repeat:

Add file → Upload files → select Week_2_Firmware_Development_Report.docx → Commit changes

So don't look for "Add file" on the current README screen. 👍

Right now, your only job is: click the ✏️ pencil icon shown in your screenshot and add the README content.

If you click the pencil and get the editing screen, send me a screenshot before clicking anything else and I'll guide you from there. 😊

Library
/
README.md
YuvaIntern – Week 2 Task
Firmware Development and Implementation
Project: Timer Interrupt Based LED Controller

This project demonstrates a simple embedded firmware application developed using Embedded C.

The firmware simulates a timer interrupt based LED controller. A simulated timer generates a periodic interrupt, and the interrupt service routine toggles the LED state.

Objectives
Understand firmware development using Embedded C
Understand timer-based interrupts
Implement an interrupt service routine
Simulate GPIO/LED control
Practice firmware testing and debugging
Document the implementation clearly
Files
timer_led_controller.c – Main Embedded C firmware source code
README.md – Project documentation
Week_2_Firmware_Development_Report.docx – Detailed project report
Firmware Operation

The simulated timer counts ticks. When the counter reaches 1000 ticks, a timer interrupt is generated. The interrupt service routine toggles the LED state. The simulation runs for 5000 ticks, allowing the interrupt and LED behavior to be verified.

Testing

The firmware was tested using a software simulation. The timer period was configured as 1000 ticks and the simulation was executed for 5000 ticks.

The LED changes state whenever the simulated timer interrupt occurs.

Compilation

Using GCC:

gcc timer_led_controller.c -o timer_led_controller
Run

Linux/macOS:

./timer_led_controller

Windows:

timer_led_controller.exe
Learning Outcomes

This task improved understanding of Embedded C, timer interrupts, interrupt service routines, GPIO control, firmware structure, testing, debugging, and documentation.

Note

This is a hardware-independent simulation. For a real microcontroller, the simulated timer and GPIO functions can be replaced with device-specific timer registers, GPIO registers, and interrupt-vector configuration.
