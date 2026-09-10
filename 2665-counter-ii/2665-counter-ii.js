/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let n = init;
    return{
        increment: function(){
            return ++n;
        },

        reset: function(){
            n = init;
            return n;
        },

        decrement: function(){
            return --n;
        }

    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */