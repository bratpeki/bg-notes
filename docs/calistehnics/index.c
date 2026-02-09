
#include "../../bookgen/bg.h"

#define TITLE "List of Calisthenic Exercises"
#define ALTERNATING " <sup>A</sup>"

void LI_INDENTED(int level, const char* text) {
	BG_TXTF("<li style=\"margin-left: %dpt\">%s</li>",
		(level-1)*15,
		text
	);
}

void HEADER( const char* a, const char* b, const char* c ) {
	BG_TABLEROW();
		BG_TH_A(a, "width=\"33%\"");
		BG_TH_A(b, "width=\"33%\"");
		BG_TH_A(c, "width=\"33%\"");
	BG_END_TABLEROW();
}

void EXERCISE( const char* a, const char* b, const char* c ) {
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
			BG_STYLE("../bookgen/styles/default-light.css");
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
						LI_INDENTED(3, "Lats");
						LI_INDENTED(3, "Rhomboids");
						LI_INDENTED(3, "Traps");
					LI_INDENTED(2, "Biceps");
					LI_INDENTED(2, "Forearms");
					LI_INDENTED(2, "Rear Delts (technically part of the shoulder, but trained by pulling)");

				LI_INDENTED(1, "Legs");
					LI_INDENTED(2, "Adductors, Abductors (opposite each other)");
					LI_INDENTED(2, "Calves, Tibialis Anterior (opposite each other)");
					LI_INDENTED(2, "Glutes");
					LI_INDENTED(2, "Hamstrings");
					LI_INDENTED(2, "Quads");

				LI_INDENTED(1, "Core");
					LI_INDENTED(2, "Abs, Deep Core");
					LI_INDENTED(2, "Hip Flexors");
					LI_INDENTED(2, "Lower Back");
					LI_INDENTED(2, "Obliques");

				LI_INDENTED(1, "Misc");
					LI_INDENTED(2, "Neck");

			BG_END_UL();

			BG_PAGEBREAK();

			BG_H(2, "Exercises");

			BG_TXT("The \"A\" added to some exercises means there's an alternating variant.");

			BG_H(3, "Push");

			BG_TABLE();

				HEADER("Exercise", "Primary Muscles", "Secondary Muscles");

				EXERCISE("Decline Push-ups", "Chest (Upper)", "Shoulders, Triceps");
				EXERCISE("Diamond Push-ups", "Triceps", "Chest, Shoulders");
				EXERCISE("Pike Push-ups", "Shoulders", "Chest, Triceps");
				EXERCISE("Push-ups", "Chest", "Triceps, Shoulders");
				EXERCISE("Tricep Dips", "Triceps", "Shoulders");

			BG_END_TABLE();

			BG_H(3, "Pull");

			BG_TABLE();

				HEADER("Exercise", "Primary Muscles", "Secondary Muscles");

				EXERCISE("Chin-ups", "Biceps, Lats", "Back, Forearms");
				EXERCISE("Inverted Rows", "Back", "Biceps, Forearms, Rear Delts");
				EXERCISE("Pull-ups", "Back", "Biceps, Forearms, Rear Delts");

			BG_END_TABLE();

			BG_PAGEBREAK();

			BG_H(3, "Legs");

			BG_TABLE();

				HEADER("Exercise", "Primary Muscles", "Secondary Muscles");

				EXERCISE("Bulgarian Split Squats", "Glutes, Quads", "Calves, Hamstrings");
				EXERCISE("Calf Raises and Elevated Calf Raises", "Calves", "");
				EXERCISE("Lunges", "Glutes, Quads", "Hamstrings");
				EXERCISE("Pistol Squats", "Glutes, Quads", "Core, Hamstrings");
				EXERCISE("Side-Lying Leg Raises", "Abductors", "");
				EXERCISE("Squats", "Glutes, Quads", "Hamstrings");
				EXERCISE("Sumo Squats", "Adductors", "");

			BG_END_TABLE();

			BG_PAGEBREAK();

			BG_H(3, "Core");

			BG_TABLE();

				HEADER("Exercise", "Primary Muscles", "Secondary Muscles");

				EXERCISE("Body Saw Planks", "Deep Core", "Calves, Shoulders");
				EXERCISE("Crunches", "Abs", "Hip Flexors");
				EXERCISE("Flutter Kicks", "Abs", "Deep Core, Hip Flexors");
				EXERCISE("Full Plank Arm Extensions", "Deep Core", "Shoulders, Triceps");
				EXERCISE("Full Plank Shoulder Taps", "Deep Core", "Shoulders, Triceps");
				EXERCISE("Heel Touches", "Obliques", "Abs");
				EXERCISE("Hollow Body Hold", "Deep Core", "");
				EXERCISE("In and Outs" ALTERNATING, "Abs, Deep Core", "Hip Flexors");
				EXERCISE("L-Sit Hold", "Deep Core", "Hip Flexors");
				EXERCISE("Lying Leg Raises" ALTERNATING, "Abs (Lower)", "Hip Flexors");
				EXERCISE("Mountain Climbers", "Abs, Deep Core", "Hip Flexors, Shoulders, Triceps");
				EXERCISE("Russian Twists", "Obliques", "Abs, Deep Core");
				EXERCISE("Seated Leg Raises", "Hip Flexors", "");
				EXERCISE("Seated Twists", "Obliques", "Abs, Deep Core");
				EXERCISE("Side Planks", "Obliques", "Deep Core, Shoulders");
				EXERCISE("Superman", "Lower Back", "Glutes, Hamstrings");

			BG_END_TABLE();

			BG_H(3, "Misc");

			BG_TABLE();

				HEADER("Exercise", "Primary Muscles", "Secondary Muscles");

				EXERCISE("Chin Tucks", "Neck", "");
				EXERCISE("Isometric Neck Holds", "Neck", "");
				EXERCISE("Lie Down Head Lifts (Front, Back and Side)", "Neck", "");

			BG_END_TABLE();

		BG_END_BODY_PRINT();

	BG_END_HTML();

	return 0;

}
