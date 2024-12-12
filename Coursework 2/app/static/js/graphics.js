
/**
 * Generates photo nav
 */
let currentIndex = 0;
const images = document.querySelectorAll('.carousel-images img');

function showImage(index) {
    images.forEach((img, i) => {
        img.classList.toggle('active', i === index);
    });
}

function prevImage() {
    currentIndex = (currentIndex > 0) ? currentIndex - 1 : images.length - 1;
    showImage(currentIndex);
}

function nextImage() {
    currentIndex = (currentIndex < images.length - 1) ? currentIndex + 1 : 0;
    showImage(currentIndex);
}

/**
 * Generates a 5-star graphic based on a float value
 */
function generateStars(rating, container) {
    const starContainer = document.getElementById(container);
    const tooltip = starContainer.querySelector('.rating-tool');
    starContainer.innerHTML = ''; // Clear existing stars
    starContainer.appendChild(tooltip); // Reattach tooltip

    // Set tooltip text
    tooltip.textContent = `Rating: ${rating.toFixed(1)} / 5`;

    // Generate stars
    for (let i = 1; i <= 5; i++) {
        const star = document.createElement('span');
        if (i <= Math.floor(rating)) {
            star.innerHTML = '&#9733;'; // Full star
        } else if (i - rating < 1) {
            star.innerHTML = '&#9733;'; // part of a star
            star.style.clipPath = `inset(0 ${100 - (rating % 1) * 100}% 0 0)`;
        } else {
            star.innerHTML = '&#9734;'; // Empty star
            star.classList.add('inactive');
        }
        star.classList.add('star');
        starContainer.appendChild(star);
    }
}


function setUpRatings(ratings, containers) {
    for (let i = 0; i < ratings.length; i++) {
        generateStars(ratings[i], containers[i])
    }

}