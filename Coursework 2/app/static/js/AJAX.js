$(document).ready(function () {
    $('#order_by').change(function () {
        const selectedOrder = $(this).val(); // Get the selected order

        $.ajax({
            url: '/all-items', // The route in your Flask app
            type: 'GET',
            data: { order_by: selectedOrder }, // Send the selected order as query parameter
            success: function (response) {
                $('.card-container').html(response); // Update the card-container with the new items
            },
            error: function (xhr, status, error) {
                console.error('Error:', error); // Log any errors
                alert('An error occurred while updating items.');
            }
        });
    });
});


function addToBasket(itemId) {
    let basket = Cookies.get('basket'); // Get the basket cookie
    if (basket) {
        basket = JSON.parse(basket); // Parse it if exists
    } else {
        basket = []; // Or initialize as an empty array
    }

    if (!basket.includes(itemId)) {
        basket.push(itemId);
        Cookies.set('basket', JSON.stringify(basket), { expires: 7 }); // Set/Update the cookie
    }
}




