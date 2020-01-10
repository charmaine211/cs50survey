// Delegate submit action
$(document).on('submit', 'form', function () {

    var validate = true;
    var unanswered = new Array();

    // Loop through available sets
    $('.option').each(function () {
        // Question text
        var question = $(this).prev();
        // Validate
        if (!$(this).find('input').is(':checked')) {
            // Didn't validate ... dispaly alert or do something
            unanswered.push(question.text());
            question.css('color', 'red'); // Highlight unanswered question
            validate = false;
        }
    });

    if (unanswered.length > 0) {
        msg = "Please answer the following questions:\n" + unanswered.join('\n');
        alert(msg);
    }
    return validate;
});