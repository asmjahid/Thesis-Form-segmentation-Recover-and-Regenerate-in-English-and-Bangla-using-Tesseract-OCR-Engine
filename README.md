# Thesis


## Training Tesseract
* For training tesseract first need to save font file in "Thesis/Tesseract Train/Training/"
* Then Run init.sh with command $ ./init.sh
* add text2image command for specific font with directory in makebox.sh File
* Run make.sh with command $ ./make.sh
* Then if need to edit box file, do it manually. Here is details about [box file](https://github.com/tesseract-ocr/tesseract/wiki/TrainingTesseract#Make-Box-Files) Edit.
* After fixing box file run Train.sh with command $ ./Train.sh

## Run Main Thesis File
* Go to Thesis/Src folder
* Run opencv script with src code filename. $sh opencv main.cpp
