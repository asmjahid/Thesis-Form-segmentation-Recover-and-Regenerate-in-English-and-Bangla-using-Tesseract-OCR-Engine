lang="eng"
rm errorlog
FontName=("Arial" "Arial Bold" "Arial Bold" "Arial Bold Italic" "Arial Heavy" "Arial Italic" "Calibri" "Calibri Bold" "Calibri Bold Italic" "Calibri Italic" "Calibri Light" "Calibri Light Italic" "Courier New" "Courier New Bold" "Courier New Bold Italic" "Courier New Italic" "Times new Roman," "Times New Roman, Bold" "Times New Roman, Bold Italic" "Times New Roman, Italic")

OutputBase=("Arial" "Arial" "Arial" "Arial" "Arial" "Arial" "Calibri" "Calibri" "Calibri" "Calibri" "Calibri" "Calibri" "Courier" "Courier" "Courier" "Courier" "TimesNewRoman" "TimesNewRoman" "TimesNewRoman" "TimesNewRoman")


for i in "${!FontName[@]}"; do 
	fontname=${FontName[$i]}
	BASE="$lang.${OutputBase[$i]}.exp$i"
	text2image --text=training.txt --outputbase=$BASE --font="$fontname" --fonts_dir=.
	if [ $? -eq 0 ]
	then 
		echo "Successfully execute: $fontname" >> errorlog
	else
		echo "Failed to build: $fontname" >> errorlog
	fi
done

cat errorlog
#text2image --text=training.txt --outputbase=eng.TimesNewRoman.exp0 --font='Times New Roman,' --fonts_dir=.


#text2image --text=training.txt --outputbase=eng.TimesNewRoman.exp1 --font='Times New Roman, Bold' --fonts_dir=.


#text2image --text=training.txt --outputbase=eng.TimesNewRoman.exp2 --font='Times New Roman, Bold Italic' --fonts_dir=.


#text2image --text=training.txt --outputbase=eng.TimesNewRoman.exp3 --font='Times New Roman, Italic' --fonts_dir=.



