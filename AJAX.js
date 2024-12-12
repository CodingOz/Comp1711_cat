$(document).ready(function () {
    $('#order_by').change(function () {
        const selectedOrder = $(this).val(); // Get the selected order

        $.ajax({
            url: '/all-items', // The route in your Flask app
            type: 'GET',
            data: { order_by: selectedOrder }, // Send the selected order as query parameter
            success: function (response) {
                $('#items-container').html(response);
            },
            error: function (xhr, status, error) {
                console.error('Error:', error); // Log any errors
                alert('An error occurred while updating items.');
            }
        });
    });
});

