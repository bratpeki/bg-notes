
#include "../../bookgen/bg.h"

#define TITLE "List of Calisthenic Exercises"

void LI_INDENTED(int level, const char* text) {
	BG_TXTF("<li style=\"margin-left: %dpt\">%s</li>",
		(level-1)*15,
		text
	);
}

void TABLE3H( const char* a, const char* b, const char* c ) {
	BG_TABLEROW();
		BG_TH_A(a, "width=\"33%\"");
		BG_TH_A(b, "width=\"33%\"");
		BG_TH_A(c, "width=\"33%\"");
	BG_END_TABLEROW();
}

void TABLE3( const char* a, const char* b, const char* c ) {
	BG_TABLEROW();
		BG_TD(a);
		BG_TD(b);
		BG_TD(c);
	BG_END_TABLEROW();
}

int main() {

	BG_INIT();

	BG_HTML();

		BG_HEAD();
			BG_DOCTITLE(TITLE);
			BG_STYLE("../bookgen/styles/default-dark.css");
			BG_STYLE_PRINT();
		BG_END_HEAD();

		BG_BODY_PRINT();

			BG_H(1, TITLE);
			BG_TXT(
			"Allows easily looking up what exercises hit what muscle group, "
			"so you can make a routine that works best for you and still hits everything."
			);

			BG_H(2, "Muscles by Group");

			BG_UL();

				LI_INDENTED(1, "Push");
					LI_INDENTED(2, "Chest");
					LI_INDENTED(2, "Shoulders");
					LI_INDENTED(2, "Triceps");

				LI_INDENTED(1, "Pull");
					LI_INDENTED(2, "Back");
						LI_INDENTED(3, "Traps");
						LI_INDENTED(3, "Lats");
						LI_INDENTED(3, "Rhomboids");
					LI_INDENTED(2, "Biceps");
					LI_INDENTED(2, "Rear Delts (technically part of the shoulder, but trained by pulling)");
					LI_INDENTED(2, "Forearms");

				LI_INDENTED(1, "Legs");
					LI_INDENTED(2, "Quads");
					LI_INDENTED(2, "Hamstrings");
					LI_INDENTED(2, "Glutes");
					LI_INDENTED(2, "Calves, Tibialis Anterior (opposite each other)");
					LI_INDENTED(2, "Adductors, Abductors (opposite each other)");

				LI_INDENTED(1, "Core");
					LI_INDENTED(2, "Abs, Deep Core");
					LI_INDENTED(2, "Obliques");
					LI_INDENTED(2, "Lower Back");
					LI_INDENTED(2, "Hip Flexors");

				LI_INDENTED(1, "Misc");
					LI_INDENTED(2, "Neck");

			BG_END_UL();

			BG_PAGEBREAK();

			BG_H(2, "Exercises");

			BG_H(3, "Push");

			BG_TABLE();

				TABLE3H("Exercise", "Primary Muscles", "Secondary Muscles");

				TABLE3("Push-ups", "Chest", "Triceps, Shoulders");
				TABLE3("Decline Push-ups", "Chest (Upper)", "Shoulders, Triceps");
				TABLE3("Pike Push-ups", "Shoulders", "Chest, Triceps");
				TABLE3("Tricep Dips", "Triceps", "Shoulders");
				TABLE3("Diamond Push-ups", "Triceps", "Chest, Shoulders");

			BG_END_TABLE();

			BG_H(3, "Pull");

			BG_TABLE();

				TABLE3H("Exercise", "Primary Muscles", "Secondary Muscles");

				TABLE3("Pull-ups", "Back", "Biceps, Forearms, Rear Delts");
				TABLE3("Inverted Rows", "Back", "Biceps, Forearms, Rear Delts");
				TABLE3("Chin-ups", "Biceps, Lats", "Back, Forearms");

			BG_END_TABLE();

			BG_PAGEBREAK();

			BG_H(3, "Legs");

			BG_TABLE();

				TABLE3H("Exercise", "Primary Muscles", "Secondary Muscles");

				TABLE3("Squats", "Quads, Glutes", "Hamstrings");
				TABLE3("Lunges", "Quads, Glutes", "Hamstrings");
				TABLE3("Bulgarian Split Squats", "Quads, Glutes", "Hamstrings, Calves");
				TABLE3("Pistol Squats", "Quads, Glutes", "Hamstrings, Core");
				TABLE3("Calf Raises and Elevated Calf Raises", "Calves", "");
				TABLE3("Sumo Squats", "Adductors", "");
				TABLE3("Side-Lying Leg Raises", "Abductors", "");

			BG_END_TABLE();

			BG_PAGEBREAK();

			BG_H(3, "Core");

			BG_TABLE();

				TABLE3H("Exercise", "Primary Muscles", "Secondary Muscles");

				TABLE3("Crunches", "Abs", "Hip Flexors");
				TABLE3("Lying Leg Raises", "Abs (Lower)", "Hip Flexors");
				TABLE3("L-Sit Hold", "Deep Core", "Hip Flexors");
				TABLE3("Body Saw Planks", "Deep Core", "Shoulders, Calves");
				TABLE3("Full Plank Arm Extensions", "Deep Core", "Shoulders, Triceps");
				TABLE3("Full Plank Shoulder Taps", "Deep Core", "Shoulders, Triceps");
				TABLE3("Hollow Body Hold", "Deep Core", "");
				TABLE3("Russian Twists", "Obliques", "Abs, Deep Core");
				TABLE3("Heel Touches", "Obliques", "Abs");
				TABLE3("Side Planks", "Obliques", "Deep Core, Shoulders");
				TABLE3("Superman", "Lower back", "Glutes, Hamstrings");
				TABLE3("Seated Leg Raises", "Hip Flexors", "");

			BG_END_TABLE();

			BG_H(3, "Misc");

			BG_TABLE();

				TABLE3H("Exercise", "Primary Muscles", "Secondary Muscles");

				TABLE3("Lie Down Head Lifts (Front, Back and Side)", "Neck", "");
				TABLE3("Chin Tucks", "Neck", "");
				TABLE3("Isometric Neck Holds", "Neck", "");

			BG_END_TABLE();

		BG_END_BODY_PRINT();

	BG_END_HTML();

	return 0;

}
