document.getElementById("submit").onclick = function() {
	document.getElementById("people").style.display = "none";
	document.getElementById("people-icon").style.display = "none";
	document.getElementById("people-label").style.display = "none";
	document.getElementById("kill_frequency").style.display = "none";
	document.getElementById("kill_frequency-icon").style.display = "none";
	document.getElementById("kill_frequency-label").style.display = "none";
	document.getElementById("survivors").style.display = "none";
	document.getElementById("survivors-icon").style.display = "none";
	document.getElementById("survivors-label").style.display = "none";
	document.getElementById("submit").style.display = "none";

	document.getElementById("spinner").style.display = "block";

	var left = 0,
		num;
	var peopleList = [];
	var people = document.getElementById("people").value;
	var kill = document.getElementById("kill_frequency").value;
	var survivors = document.getElementById("survivors").value;

	for (i = 0; i < people; i++) {
		peopleList[i] = i + 1;
	}

	while (peopleList.length > survivors) {
		num = kill - left;

		if (num > peopleList.length) {
			while (num > peopleList.length) {
				num = num - peopleList.length;
			}
		}

		while (num <= peopleList.length) {
			peopleList[num - 1] = 0;
			num = +num + +kill;
		}

		for (j = peopleList.length - 1; j >= 0; j--) {
			if (peopleList[j] == 0) {
				left = peopleList.length - (j + 1);
				break;
			}
		}

		var len = peopleList.length
		while (len--) {
			if (peopleList[len] == 0) {
				peopleList.splice(len, 1);
			}
		}
	}

	var survivorIDs = "";

	for (k = 0; k < peopleList.length; k++) {
		if (k == (peopleList.length - 1)) {
			survivorIDs = survivorIDs + peopleList[k];
		} else {
			survivorIDs = survivorIDs + peopleList[k] + ", ";
		}
	}

	document.getElementById("spinner").style.display = "none";
	document.getElementById("survivor_head").style.display = "block";
	document.getElementById("survivor_ids").style.display = "block";
	document.getElementById("survivor_ids").innerHTML = survivorIDs;
	document.getElementById("retry").style.display = "block";
}

document.getElementById("retry").onclick = function() {
	location.reload();
}